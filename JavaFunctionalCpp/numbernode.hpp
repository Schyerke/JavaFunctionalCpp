#ifndef NUMBERNODE_HPP
#define NUMBERNODE_HPP

#include <iostream>
#include "astnode.hpp"

class NumberNode : public AstNode
{
public:
	long number;
	NumberNode(long number);

	std::string get_classname();
};
#endif // !NUMBERNODE_HPP
