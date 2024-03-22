#include "functionstmtnode.hpp"

FunctionStmtNode::FunctionStmtNode(Variable var, std::vector<Variable>& formal_parameters)
	: formal_parameters(formal_parameters)
{
	this->var = std::move(var);
}

std::any FunctionStmtNode::accept(Visitor& visitor)
{
	return visitor.visitFunctionStmtNode(*this);
}

