#include "stringnode.hpp"

StringNode::StringNode(std::string value)
{
	this->value = value;
}


std::any StringNode::accept(Visitor& visitor)
{
	return visitor.visitStringNode(*this);
}
