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

std::any VarDeclarationNode::accept(Visitor& visitor)
{
	return visitor.visitVarDeclarationStmt(*this);
}

