#include <iostream>
#include "numbernode.hpp"


NumberNode::NumberNode(long number)
{
	this->number = number;
}

std::string NumberNode::get_classname() {
	std::string classname = "(" + number;
	classname.append("_NumberNode)");
	classname.append("\n");
	return classname;
}
