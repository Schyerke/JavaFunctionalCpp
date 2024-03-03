#include "boolnode.hpp"

BoolNode::BoolNode(bool value)
{
	this->value = value;
}

std::string BoolNode::get_classname()
{
	std::string result = "false";
	if (this->value) result = "true";
	return result;
}
