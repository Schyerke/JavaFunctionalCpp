#ifndef STRING_NODE_HPP
#define STRING_NODE_HPP

#include <iostream>
#include "astnode.hpp"

class StringNode : public AstNode
{
public:
	std::string value;

	StringNode(std::string value);
	std::any accept(Visitor& visitor);
};


#endif // !STRING_NODE_HPP
