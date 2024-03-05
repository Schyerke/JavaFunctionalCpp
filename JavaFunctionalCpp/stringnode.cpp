#include "stringnode.hpp"

StringNode::StringNode(std::string value)
{
	this->value = value;
}

std::string StringNode::get_classname()
{
	return "String " + this->value;
}
