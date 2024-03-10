#include "identifiernode.hpp"

IdentifierNode::IdentifierNode(std::string identifier)
{
	this->identifier = identifier;
}

std::any IdentifierNode::accept(Visitor& visitor)
{
	return visitor.visitIdentifierNode(*this);
}
