#include "ifstmtnode.hpp"

IfStmtNode::IfStmtNode(std::unique_ptr<AstNode> expression, std::unique_ptr<AstNode> blockStmt)
{
	this->expression = std::move(expression);
	this->blockStmt = std::move(blockStmt);
}

std::any IfStmtNode::accept(Visitor& visitor)
{
	return visitor.visitIfStmtNode(*this);
}

