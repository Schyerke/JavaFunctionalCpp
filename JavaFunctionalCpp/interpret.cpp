#include "interpret.hpp"

std::any Interpreter::interpret(std::unique_ptr<AstNode> root)
{
    return root->accept(*this);
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

        case EQUAL_EQUAL:
            return left == right;
        case BANG_EQUAL:
            return left != right;
    }
}

template<typename T>
std::any Interpreter::eva_bool(T left, Token_t op, T right)
{
    switch (op)
    {
        case AMPERSAND_AMPERSAND:
            return left && right;
        case PIPE_PIPE:
            return left || right;
    }
}

std::any Interpreter::visitNumberNode(NumberNode& numberNode)
{
    return numberNode.number;
}

std::any Interpreter::visitStringNode(StringNode& stringNode)
{
    return std::any();
}

std::any Interpreter::visitUnaryNode(UnaryNode& unaryNode)
{
    std::any unary_expr = unaryNode.left->accept(*this);
    if (unary_expr.type().name() == "int")
    {
        return -std::any_cast<int>(unary_expr);
    }
    if (unary_expr.type().name() == "long")
    {
        return -std::any_cast<long>(unary_expr);
    }
}

std::any Interpreter::visitBinaryExpression(BinaryExpression& binaryExpression)
{
    std::any left_t = binaryExpression.left->accept(*this);
    std::any right_t = binaryExpression.right->accept(*this);
    Token_t op = binaryExpression.op;

    if (left_t.type().name() == "int" && right_t.type().name() == "int")
    {
        return eva_num(std::any_cast<int>(left_t), op, std::any_cast<int>(right_t));
    }
    if (left_t.type().name() == "long" && right_t.type().name() == "long")
    {
        return eva_num(std::any_cast<long>(left_t), op, std::any_cast<long>(right_t));
    }
    if (left_t.type().name() == "bool" && right_t.type().name() == "bool")
    {
        return eva_bool(std::any_cast<bool>(left_t), op, std::any_cast<bool>(right_t));
    }
}

std::any Interpreter::visitBoolNode(BoolNode& boolNode)
{
    return std::any();
}

