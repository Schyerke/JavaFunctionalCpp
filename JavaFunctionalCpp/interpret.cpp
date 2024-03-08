#include "interpret.hpp"

void Interpreter::interpret()
{

}

std::any Interpreter::visitNumberNode(NumberNode& numberNode)
{
    return numberNode.number;
}

std::any Interpreter::visitUnaryNode(UnaryNode& unaryNode)
{
    std::any unary_expr = unaryNode.accept(unaryNode.left);
}

std::any Interpreter::visitBinaryExpression(BinaryExpression& binaryExpression)
{
    return std::any();
}
