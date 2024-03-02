#include "evaluator.hpp"
#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "unarynode.hpp"
#include "expressionstmtnode.hpp"
#include "printstmtnode.hpp"

Evaluator::Evaluator()
{
}

long Evaluator::evaluate(AstNode* node)
{
    // Expression
    if (UnaryNode* unaryNode = dynamic_cast<UnaryNode*>(node))
    {
        return -evaluate(unaryNode->left.get());
    }
    if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node))
    {
        return numberNode->number;
    }
    if (BinaryExpression* binaryOperationNode = dynamic_cast<BinaryExpression*>(node))
    {
        long left = evaluate(binaryOperationNode->left.get());
        long right = evaluate(binaryOperationNode->right.get());
        Token_t op = binaryOperationNode->op;

        switch (op)
        {
            case PLUS_TOKEN:
                return left + right;
            case MINUS_TOKEN:
                return left - right;
            case STAR_TOKEN:
                return left * right;
            case SLASH_TOKEN:
                return (long)(left / right);
            case NO_OPERATOR_TOKEN:
                return left;
            default:
                std::cout << "No operator found (error)";
        }
    }

    // Statements
    if (ExpressionStmtNode* exprStmtNode = dynamic_cast<ExpressionStmtNode*>(node))
    {
        return evaluate(exprStmtNode->expression);
    }
    if (PrintStmtNode* printStmtNode = dynamic_cast<PrintStmtNode*>(node))
    {
        long result = evaluate(printStmtNode->expression);
        std::cout << result;
    }

    return -1;
}
