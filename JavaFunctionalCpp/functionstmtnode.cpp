#include "functionstmtnode.hpp"

FunctionStmtNode::FunctionStmtNode(FuncVariable var, std::vector<Variable> formal_parameters)
{
	this->var = std::move(var);
	this->formal_parameters = std::move(formal_parameters);
}

std::any FunctionStmtNode::accept(Visitor& visitor)
{
	return visitor.visitFunctionStmtNode(*this);
}

