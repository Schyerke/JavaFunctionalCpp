#include "vardeclarationnode.hpp"

VarDeclarationNode::VarDeclarationNode(Token_t variableType, std::string identifier)
{
	this->variableType = variableType;
	this->identifier = identifier;
}

std::string VarDeclarationNode::get_classname()
{
	return "Identifier " + this->identifier;
}


