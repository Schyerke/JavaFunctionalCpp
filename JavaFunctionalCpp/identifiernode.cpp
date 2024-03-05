#include "identifiernode.hpp"

IdentifierNode::IdentifierNode(std::string identifier)
{
	this->identifier = identifier;
}

std::string IdentifierNode::get_classname()
{
	return "Identifier " + this->identifier;
}


