#include "vardeclarationnode.hpp"

VarDeclarationNode::VarDeclarationNode(Token_t variableType, std::string identifier)
{
	this->variableType = variableType;
	this->identifier = identifier;
}

VarDeclarationNode::VarDeclarationNode(Token_t variableType, std::string identifier, std::string value)
{
	this->variableType = variableType;
	this->identifier = identifier;
	this->value = value;
}

std::string VarDeclarationNode::get_classname()
{
	return "Identifier " + this->identifier;
}


