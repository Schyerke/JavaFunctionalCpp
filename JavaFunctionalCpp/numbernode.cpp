#include <iostream>
#include <string>
#include "numbernode.hpp"


NumberNode::NumberNode(NUMBER_DT number)
{
	this->number = number;
}

std::any NumberNode::accept(Visitor& visitor)
{
	return visitor.visitNumberNode(*this);
}
