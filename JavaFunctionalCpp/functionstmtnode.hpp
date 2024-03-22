#pragma once

#include <vector>

#include "astnode.hpp"
#include "variable.hpp"

class FunctionStmtNode : public AstNode 
{
public:

	FunctionStmtNode(Variable var, std::vector<Variable>& formal_parameters);

	std::any accept(Visitor& visitor);
	
	Variable var;
	std::vector<Variable>& formal_parameters;
};