#include "expressionstmtnode.hpp"

ExpressionStmtNode::ExpressionStmtNode(std::unique_ptr<AstNode> expression)
{
	this->expression = std::move(expression);
}
