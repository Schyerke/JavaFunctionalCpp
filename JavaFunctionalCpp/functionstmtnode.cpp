#include "functionstmtnode.hpp"

FunctionStmtNode::FunctionStmtNode(Variable var, std::vector<Variable>& formal_parameters, std::unique_ptr<AstNode>& blockstmt)
	: formal_parameters(formal_parameters), blockstmt(blockstmt)
{
	this->var = var;
}

std::any FunctionStmtNode::accept(Visitor& visitor)
{
	return visitor.visitFunctionStmtNode(*this);
}

