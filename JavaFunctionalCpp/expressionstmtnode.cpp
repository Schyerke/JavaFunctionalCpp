#include "expressionstmtnode.hpp"

ExpressionStmtNode::ExpressionStmtNode(std::unique_ptr<AstNode> expression)
{
	this->expression = std::move(expression);
}

std::any ExpressionStmtNode::accept(Visitor& visitor)
{
	return visitor.visitExpressionStmt(*this);
}
