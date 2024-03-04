#include "evaluator.hpp"
#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "unarynode.hpp"
#include "boolnode.hpp"
#include "expressionstmtnode.hpp"
#include "printstmtnode.hpp"

Evaluator::Evaluator()
{
}

Result Evaluator::evaluate(AstNode* node)
{
    // Expression
    if (UnaryNode* unaryNode = dynamic_cast<UnaryNode*>(node))
    {
        Result result = evaluate(unaryNode->left.get());
        result.number = -result.number;
        return result;
    }
    if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node))
    {
        Result result = {};
        result.resultType = NUMBER;
        result.number = numberNode->number;
        return result;
    }
    if (BoolNode* boolNode = dynamic_cast<BoolNode*>(node))
    {
        Result result = {};
        result.resultType = BOOLEAN;
        result.boolean = boolNode->value;
        return result;
    }
    if (BinaryExpression* binaryOperationNode = dynamic_cast<BinaryExpression*>(node))
    {
        Result left_r = evaluate(binaryOperationNode->left.get());
        Result right_r = evaluate(binaryOperationNode->right.get());
        Token_t op = binaryOperationNode->op;
        Result result = {};
        if (left_r.resultType == NUMBER && right_r.resultType == NUMBER)
        {
            long left = left_r.number;
            long right = right_r.number;
            switch (op)
            {
            case PLUS_TOKEN:
                result.number = left + right;
                break;
            case MINUS_TOKEN:
                result.number = left - right;
                break;
            case STAR_TOKEN:
                result.number = left * right;
                break;
            case SLASH_TOKEN:
                result.number = (long)(left / right);
                break;

            case EQUAL_EQUAL:
                result.boolean = left == right;
                result.resultType = BOOLEAN;
                break;
            case BANG_EQUAL:
                result.boolean = left != right;
                result.resultType = BOOLEAN;
                break;

            default:
                std::cout << "No operator found (error)";
            }
        }
        else if (left_r.resultType == BOOLEAN && right_r.resultType == BOOLEAN) {
            bool left = left_r.boolean;
            bool right = right_r.boolean;
            
            result.resultType = BOOLEAN;
            switch (op) {
            case EQUAL_EQUAL:
                result.boolean = left == right;
                break;
            case BANG_EQUAL:
                result.boolean = left != right;
                break;
            case AMPERSAND_AMPERSAND:
                result.boolean = left && right;
                break;
            case PIPE_PIPE:
                result.boolean = left || right;
                break;
            }
        }
        return result;
    }

    // Statements
    if (ExpressionStmtNode* exprStmtNode = dynamic_cast<ExpressionStmtNode*>(node))
    {
        return evaluate(exprStmtNode->expression);
    }
    if (PrintStmtNode* printStmtNode = dynamic_cast<PrintStmtNode*>(node))
    {
        Result result = evaluate(printStmtNode->expression);
        switch (result.resultType)
        {
        case NUMBER:
            std::cout << result.number;
            break;
        case BOOLEAN:
            if (result.boolean) {
                std::cout << "true";
            }
            else {
                std::cout << "false";
            }
            break;
        }
    }
    
    Result result = {};
    result.resultType = NO_RESULT;
    return result;
}
