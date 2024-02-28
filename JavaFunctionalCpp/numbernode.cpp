#include <iostream>
#include <string>
#include "numbernode.hpp"


NumberNode::NumberNode(long number)
{
	this->number = number;
}

std::string NumberNode::get_classname() {
	std::string classname = "(" + std::to_string(number) + " Number Node)";
	classname.append("\n");
	return classname;
}
