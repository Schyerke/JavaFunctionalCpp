#pragma once

#include <vector>

#include "astnode.hpp"
#include "variable.hpp"

class FunctionStmtNode : public AstNode 
{
public:

	FunctionStmtNode(std::string identifier, std::vector<Variable> formal_parameters);

	std::any accept(Visitor& visitor);
	
	std::string identifier;
	std::vector<Variable> formal_parameters;
};