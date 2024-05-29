#include "varassignmentstmtnode.hpp"

VarAssignmentStmtNode::VarAssignmentStmtNode(std::string identifier, std::unique_ptr<AstNode> expression)
{
	this->identifier = identifier;
	this->expression = std::move(expression);
}

std::any VarAssignmentStmtNode::accept(Visitor& visitor)
{
	return visitor.visitVarAssignmentStmt(*this);
}
