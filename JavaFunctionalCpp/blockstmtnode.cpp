#include "blockstmtnode.hpp"

BlockStmtNode::BlockStmtNode(std::vector<std::unique_ptr<AstNode>>& stmts)
	: stmts(stmts)
{
}

std::any BlockStmtNode::accept(Visitor& visitor)
{
	return visitor.visitBlockStmtNode(*this);
}