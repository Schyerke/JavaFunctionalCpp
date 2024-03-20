
#include <variant>

#include "interpret.hpp"

#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "boolnode.hpp"
#include "unarynode.hpp"
#include "stringnode.hpp"
#include "identifiernode.hpp"

#include "expressionstmtnode.hpp"
#include "printstmtnode.hpp"
#include "vardeclarationnode.hpp"
#include "varassignmentstmtnode.hpp"

Interpreter::Interpreter(Enviroment& env) : env(env)
{
    
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

template<typename T>
std::any Interpreter::eva_num(T left, Token_t op, T right)
{
    switch (op)
    {
        case PLUS_TOKEN:
            return left + right;
        case MINUS_TOKEN:
            return left - right;
        case STAR_TOKEN:
            return left * right;
        case SLASH_TOKEN:
            return (T)(left / right);

        case EQUAL_EQUAL_TOKEN:
            return left == right;
        case BANG_EQUAL_TOKEN:
            return left != right;
    }
    std::string op_err = token_name(op);
    throw std::invalid_argument("Runtime Error: Invalid value type (found type '" + op_err + "')");
}

template<typename T>
std::any Interpreter::eva_bool(T left, Token_t op, T right)
{
    switch (op)
    {
        case AMPERSAND_AMPERSAND_TOKEN:
            return left && right;
        case PIPE_PIPE_TOKEN:
            return left || right;
    }
    std::string op_err = token_name(op);
    throw std::invalid_argument("Runtime Error: Invalid value type (found type '" + op_err + "')");
}

template<typename T>
std::any Interpreter::num_add(std::any value, T num)
{
    if (value.type() == typeid(short))
    {
        return std::any_cast<short>(value) + num;
    }
    if (value.type() == typeid(int))
    {
        return std::any_cast<int>(value) + num;
    }
    if (value.type() == typeid(long))
    {
        return std::any_cast<long>(value) + num;
    }
    if (value.type() == typeid(double))
    {
        return std::any_cast<double>(value) + num;
    }
    if (value.type() == typeid(float))
    {
        return std::any_cast<float>(value) + num;
    }
    std::string value_err = value.type().name();
    throw std::invalid_argument("Runtime Error: Invalid value type (found type '" + value_err + "')");
}

std::any Interpreter::visitNumberNode(NumberNode& numberNode)
{
    NUMBER_DT nn = numberNode.number;
    if (std::holds_alternative<short>(nn))
    {
        return std::get<short>(nn);
    }
    if (std::holds_alternative<int>(nn))
    {
        return std::get<int>(nn);
    }
    if (std::holds_alternative<long>(nn))
    {
        return std::get<long>(nn);
    }
    if (std::holds_alternative<float>(nn)) 
    {
        return std::get<float>(nn);
    }
    if (std::holds_alternative<double>(nn)) 
    {
        return std::get<double>(nn);
    }
    throw std::invalid_argument("Runtime Error: numberNode invalid number data type.");
}

std::any Interpreter::visitStringNode(StringNode& stringNode)
{
    return stringNode.value;
}

std::any Interpreter::visitIdentifierNode(IdentifierNode& identifierNode)
{
    Variable var = this->env.get(identifierNode.identifier);
    return var.value;
}

std::any Interpreter::visitUnaryNode(UnaryNode& unaryNode)
{
    std::any unary_expr = unaryNode.left->accept(*this);
    if (unary_expr.type() == typeid(short))
    {
        return -std::any_cast<short>(unary_expr);
    }
    if (unary_expr.type() == typeid(int))
    {
        return -std::any_cast<int>(unary_expr);
    }
    if (unary_expr.type() == typeid(long))
    {
        return -std::any_cast<long>(unary_expr);
    }
    if (unary_expr.type() == typeid(float))
    {
        return -std::any_cast<float>(unary_expr);
    }
    if (unary_expr.type() == typeid(double))
    {
        return -std::any_cast<double>(unary_expr);
    }
    std::string unary_err = unary_expr.type().name();
    throw std::invalid_argument("Runtime Error: Invalid unary value type (found type '" + unary_err + "')");
}

std::any Interpreter::visitExpressionStmt(ExpressionStmtNode& expressionStmtNode)
{
    std::any expr = expressionStmtNode.expression->accept(*this);
    std::variant<int, std::string> result;
    if (expr.type() == typeid(int))
    {
        result = std::any_cast<int>(expr);
    }
    else if (expr.type() == typeid(std::string))
    {
        result = std::any_cast<std::string>(expr);
    }
    else 
    {
        throw std::invalid_argument("Runtime Error: repl accepts either 'int' or 'string'.");
    }

    if (std::holds_alternative<int>(result))
    {
        std::cout << "Repl: " << std::get<int>(result);
    }
    if (std::holds_alternative<std::string>(result))
    {
        std::cout << "Repl: " << std::get<std::string>(result);
    }
    return std::any();
}

std::any Interpreter::visitPrintStmt(PrintStmtNode& printStmtNode)
{
    std::any expr_r = printStmtNode.expression->accept(*this);

    
    if (expr_r.type() == typeid(short)) 
    {
        std::cout << std::any_cast<short>(expr_r);
    }
    else if (expr_r.type() == typeid(int)) 
    {
        std::cout << std::any_cast<int>(expr_r);
    }
    else if (expr_r.type() == typeid(long)) 
    {
        std::cout << std::any_cast<long>(expr_r);
    }
    else if (expr_r.type() == typeid(float)) 
    {
        std::cout << std::any_cast<float>(expr_r);
    }
    else if (expr_r.type() == typeid(double))
    {
        std::cout << std::any_cast<double>(expr_r);
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
    else if (expr_r.type() == typeid(char const*))
    {
        std::cout << std::any_cast<char const*>(expr_r);
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
    this->env.set(var);
    
    return std::any();
}

std::any Interpreter::visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode)
{
    std::string identifier = varAssignmentNode.identifier;
    std::any value = varAssignmentNode.expression->accept(*this);
    this->env.assign(identifier, value);
    
    return std::any();
}

std::any Interpreter::visitBinaryExpression(BinaryExpression& binaryExpression)
{
    std::any left = binaryExpression.left->accept(*this);
    std::any right = binaryExpression.right->accept(*this);
    Token_t op = binaryExpression.op;

    if (left.type() == typeid(short) && right.type() == typeid(short))
    {
        return eva_num(std::any_cast<short>(left), op, std::any_cast<short>(right));
    }
    if (left.type() == typeid(int) && right.type() == typeid(int))
    {
        return eva_num(std::any_cast<int>(left), op, std::any_cast<int>(right));
    }
    if (left.type() == typeid(long) && right.type() == typeid(long))
    {
        return eva_num(std::any_cast<long>(left), op, std::any_cast<long>(right));
    }
    if (left.type() == typeid(float) && right.type() == typeid(float))
    {
        return eva_num(std::any_cast<float>(left), op, std::any_cast<float>(right));
    }
    if (left.type() == typeid(double) && right.type() == typeid(double))
    {
        return eva_num(std::any_cast<double>(left), op, std::any_cast<double>(right));
    }

    if (left.type() == typeid(bool) && right.type() == typeid(bool))
    {
        return eva_bool(std::any_cast<bool>(left), op, std::any_cast<bool>(right));
    }
    std::string left_err = left.type().name();
    std::string right_err = right.type().name();
    throw std::invalid_argument("Runtime Error: couldn't evaluate type '" + left_err + "' with type '" + right_err + "'");
}

std::any Interpreter::visitBoolNode(BoolNode& boolNode)
{
    return boolNode.value;
}
