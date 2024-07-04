
#include "boolnode.hpp"

BoolNode::BoolNode(bool value)
{
	this->value = value;
}

std::any BoolNode::accept(Visitor& visitor)
{
	return visitor.visitBoolNode(*this);
}