#include "functionstmtnode.hpp"

FunctionStmtNode::FunctionStmtNode(std::string identifier, std::vector<Variable> formal_parameters)
{
	this->formal_parameters = std::move(formal_parameters);
	this->identifier = identifier;
}

std::any FunctionStmtNode::accept(Visitor& visitor)
{
	return visitor.visitFunctionStmtNode(*this);
}

