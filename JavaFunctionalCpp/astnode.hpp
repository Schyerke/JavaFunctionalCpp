#ifndef ASTNODE_HPP
#define ASTNODE_HPP

#include <iostream>
#include <any>

#include "visitor.hpp"

class AstNode : 
{
public:
	virtual std::string get_classname() = 0;
	virtual	std::any accept(Visitor& visitor) = 0;
};

#endif // !ASTNODE_HPP
