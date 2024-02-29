#include "evaluator.hpp"
#include "numbernode.hpp"
#include "binaryoperationnode.hpp"

Evaluator::Evaluator()
{
}

long Evaluator::evaluate(AstNode* node)
{
    if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node)) {
        return numberNode->number;
    }
    if (BinaryOperationNode* binaryOperationNode = dynamic_cast<BinaryOperationNode*>(node)) {
        long left = evaluate(binaryOperationNode->left.get());
        long right = evaluate(binaryOperationNode->right.get());
        Token_t op = binaryOperationNode->op;
        
        switch (op) {
        case PLUS_TOKEN:
            return left + right;
        case MINUS_TOKEN:
            return left - right;
        case NO_OPERATOR_TOKEN:
            return left;
        default:
            std::cout << "No operator found (error)";
        }
    }
    return -1;
}
