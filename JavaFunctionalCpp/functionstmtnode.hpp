#pragma once

#include <vector>

#include "astnode.hpp"
#include "variable.hpp"

class FunctionStmtNode : public AstNode 
{
public:

	FunctionStmtNode(FuncVariable var, std::vector<Variable> formal_parameters);

	std::any accept(Visitor& visitor);
	
	FuncVariable var;
	std::vector<Variable> formal_parameters;
};