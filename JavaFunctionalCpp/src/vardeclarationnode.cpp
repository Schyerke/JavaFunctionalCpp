#include "vardeclarationnode.hpp"

VarDeclarationNode::VarDeclarationNode(Token_t variableType, std::string identifier, std::unique_ptr<AstNode> expression)
{
	this->variableType = variableType;
	this->identifier = identifier;
	this->expression = std::move(expression);
}

std::any VarDeclarationNode::accept(Visitor& visitor)
{
	return visitor.visitVarDeclarationStmt(*this);
}

