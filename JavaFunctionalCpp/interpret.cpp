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

Interpreter::Interpreter(Enviroment env)
{
    this->env = env;
}

std::any Interpreter::interpret(std::unique_ptr<AstNode> root)
{
    try
    {
        return root->accept(*this);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
    return std::any();
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
    return std::any();
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
    return std::any();
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
    Variable var = this->env.get(identifierNode.identifier);
    return var.value;
}

std::any Interpreter::visitUnaryNode(UnaryNode& unaryNode)
{
    std::any unary_expr = unaryNode.left->accept(*this);
    if (unary_expr.type() == typeid(int))
    {
        return -std::any_cast<int>(unary_expr);
    }
    if (unary_expr.type() == typeid(long))
    {
        return -std::any_cast<long>(unary_expr);
    }
    return std::any();
}

std::any Interpreter::visitExpressionStmt(ExpressionStmtNode& expressionStmtNode)
{
    return expressionStmtNode.expression->accept(*this);
}

std::any Interpreter::visitPrintStmt(PrintStmtNode& printStmtNode)
{
    std::any expr_result = printStmtNode.expression->accept(*this);
    if (expr_result.type() == typeid(bool))
    {
        bool r = std::any_cast<bool>(expr_result);
        std::cout << r ? "true" : "false";
    }
    if (expr_result.type() == typeid(int))
    {
        std::cout << std::any_cast<int>(expr_result);
    }
    if (expr_result.type() == typeid(long))
    {
        std::cout << std::any_cast<long>(expr_result);
    }
    if (expr_result.type() == typeid(std::string))
    {
        std::cout << std::any_cast<std::string>(expr_result);
    }
    if (expr_result.type() == typeid(char const*))
    {
        std::cout << std::any_cast<char const*>(expr_result);
    }
    return std::any();
}

std::any Interpreter::visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode)
{
    Variable var;
    var.dtType = tokent2datatype(varDeclarationNode.variableType);
    var.identifier = varDeclarationNode.identifier;
    var.value = varDeclarationNode.expression->accept(*this);
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
    std::any left_t = binaryExpression.left->accept(*this);
    std::any right_t = binaryExpression.right->accept(*this);
    Token_t op = binaryExpression.op;

    if (left_t.type() == typeid(int) && right_t.type() == typeid(int))
    {
        return eva_num(std::any_cast<int>(left_t), op, std::any_cast<int>(right_t));
    }
    if (left_t.type() == typeid(long) && right_t.type() == typeid(long))
    {
        return eva_num(std::any_cast<long>(left_t), op, std::any_cast<long>(right_t));
    }
    if (left_t.type() == typeid(bool) && right_t.type() == typeid(bool))
    {
        return eva_bool(std::any_cast<bool>(left_t), op, std::any_cast<bool>(right_t));
    }
    return std::any();
}

std::any Interpreter::visitBoolNode(BoolNode& boolNode)
{
    return boolNode.value;
}

