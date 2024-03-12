#include "varassignmentstmtnode.hpp"

VarAssignmentStmtNode::VarAssignmentStmtNode(std::string identifier, std::unique_ptr<AstNode> expression, AssignmentType at = AT_NO_OP)
{
	this->identifier = identifier;
	this->expression = std::move(expression);
	this->at = at;
}

std::any VarAssignmentStmtNode::accept(Visitor& visitor)
{
	return visitor.visitVarAssignmentStmt(*this);
}
