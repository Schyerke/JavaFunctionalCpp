#include "printstmtnode.hpp"

PrintStmtNode::PrintStmtNode(std::unique_ptr<AstNode> expression)
{
	this->expression = std::move(expression);
}

std::any PrintStmtNode::accept(Visitor& visitor)
{
	return visitor.visitPrintStmt(*this);
}
