
#include <variant>

#include "interpret.hpp"

#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "boolnode.hpp"
#include "unarynode.hpp"
#include "stringnode.hpp"
#include "identifiernode.hpp"

#include "printstmtnode.hpp"
#include "vardeclarationnode.hpp"
#include "varassignmentstmtnode.hpp"

Interpreter::Interpreter(Enviroment env)
{
    this->env = std::move(env);
}

std::any Interpreter::interpret(std::unique_ptr<AstNode> root)
{
    try
    {
        return root->accept(*this);
    }
    catch (std::invalid_argument& e)
    {
        report(e.what());
    }
    return std::any();
}

void Interpreter::report(std::string error)
{
    this->runtime_errors.push_back(error);
}

std::vector<std::string> Interpreter::get_runtime_errors()
{
    return this->runtime_errors;
}

std::any Interpreter::visitNumberNode(NumberNode& numberNode)
{
    return numberNode.number;
}

std::any Interpreter::visitStringNode(StringNode& stringNode)
{
    return stringNode.value;
}

std::any Interpreter::visitIdentifierNode(IdentifierNode& identifierNode)
{
    Variable var = std::move(this->env.var.get(identifierNode.identifier));
    return var.value;
}

std::any Interpreter::visitUnaryNode(UnaryNode& unaryNode)
{
    std::any unary_expr = unaryNode.left->accept(*this);
    if (unary_expr.type() == typeid(NUMBER_DT))
    {
        NUMBER_DT expr_unary = std::any_cast<NUMBER_DT>(unary_expr);
        return std::visit([]<class T>(T var) -> NUMBER_DT
        {
            return -(T)var;
        }, expr_unary);
    }
    std::string unary_err = unary_expr.type().name();
    throw std::invalid_argument("Runtime Error: Invalid unary value type (found type '" + unary_err + "')");
}

std::any Interpreter::visitPrintStmt(PrintStmtNode& printStmtNode)
{
    std::any expr_r = printStmtNode.expression->accept(*this);

    if (expr_r.type() == typeid(NUMBER_DT))
    {
        NUMBER_DT expr_num = std::any_cast<NUMBER_DT>(expr_r);
        std::visit([]<class T>(T value)
        {
            std::cout << value;
        }, expr_num);
    }
    else if (expr_r.type() == typeid(bool))
    {
        bool r = std::any_cast<bool>(expr_r);
        std::cout << r ? "true" : "false";
    }
    else if (expr_r.type() == typeid(std::string))
    {
        std::cout << std::any_cast<std::string>(expr_r);
    }
    else if (expr_r.type() == typeid(nullptr))
    {
        std::cout << "null";
    }
    else
    {
        std::string expr_err = expr_r.type().name();
        throw std::invalid_argument("Runtime Error: Invalid expression (found: " + expr_err + ") in print statement.");
    }
    return std::any();
}

std::any Interpreter::visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode)
{
    Variable var;
    var.dtType = from_TokenT_to_DataType(varDeclarationNode.variableType);
    var.identifier = varDeclarationNode.identifier;
    if (varDeclarationNode.expression != nullptr)
    {
        var.value = varDeclarationNode.expression->accept(*this);
    }
    else
    {
        var.value = nullptr;
    }
    this->env.var.set(var);
    
    return std::any();
}

std::any Interpreter::visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode)
{
    std::string identifier = varAssignmentNode.identifier;
    std::any value = varAssignmentNode.expression->accept(*this);
    this->env.var.assign(identifier, value);
    
    return std::any();
}

std::any Interpreter::visitFunctionStmtNode(FunctionStmtNode& functionStmtNode)
{
    return std::any();
}

std::any Interpreter::visitFunctionCallNode(FunctionCallExpr& functionCallExpr)
{
    return std::any();
}

std::any Interpreter::visitBlockStmtNode(BlockStmtNode& blockStmtNode)
{
    return std::any();
}

std::any Interpreter::visitBinaryExpression(BinaryExpression& binaryExpression)
{
    std::any left = binaryExpression.left->accept(*this);
    std::any right = binaryExpression.right->accept(*this);
    Token_t op = binaryExpression.op;

    if (left.type() == typeid(NUMBER_DT) && right.type() == typeid(NUMBER_DT))
    {
        NUMBER_DT left_num = std::any_cast<NUMBER_DT>(left);
        NUMBER_DT right_num = std::any_cast<NUMBER_DT>(right);

        NUMBER_DT result = std::visit([op]<class T1, class T2>(T1 lvar, T2 rvar) -> NUMBER_DT
        {
            switch (op)
            {
                case PLUS_TOKEN:
                    return (T1)lvar + (T2)rvar;
                case MINUS_TOKEN:
                    return (T1)lvar - (T2)rvar;
                case STAR_TOKEN:
                    return (T1)lvar * (T2)rvar;
                case SLASH_TOKEN:
                    return (T1)lvar / (T2)rvar;

                case EQUAL_EQUAL_TOKEN:
                    return (bool)((T1)lvar == (T2)rvar);
                case BANG_EQUAL_TOKEN:
                    return (bool)((T1)lvar != (T2)rvar);
                default:
                    std::string left_err = typeid(lvar).name();
                    std::string right_err = typeid(rvar).name();
                    throw std::invalid_argument("Runtime Error: couldn't evaluate type '" + left_err + "' with type '" + right_err + "'");
            }
        }, left_num, right_num);

        return result;
    }

    if (left.type() == typeid(bool) && right.type() == typeid(bool))
    {
        bool lvar = std::any_cast<bool>(left);
        bool rvar = std::any_cast<bool>(right);

        switch (op)
        {
            case AMPERSAND_AMPERSAND_TOKEN:
                return lvar && rvar;
            case PIPE_PIPE_TOKEN:
                return lvar || rvar;
        }
        std::string op_err = token_name(op);
        throw std::invalid_argument("Runtime Error: Invalid value type (found type '" + op_err + "')");
    }
    std::string left_err = left.type().name();
    std::string right_err = right.type().name();
    throw std::invalid_argument("Runtime Error: couldn't evaluate type '" + left_err + "' with type '" + right_err + "'");
}

std::any Interpreter::visitBoolNode(BoolNode& boolNode)
{
    return boolNode.value;
}
