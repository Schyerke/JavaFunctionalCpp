#include <iostream>
#include <string>
#include "numbernode.hpp"


NumberNode::NumberNode(long number)
{
	this->number = number;
}

std::any NumberNode::accept(Visitor& visitor)
{
	return visitor.visitNumberNode(*this);
}
