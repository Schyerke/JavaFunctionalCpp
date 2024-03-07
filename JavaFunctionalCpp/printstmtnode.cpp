#include "printstmtnode.hpp"

PrintStmtNode::PrintStmtNode(std::unique_ptr<AstNode> expression)
{
	this->expression = std::move(expression);
}
