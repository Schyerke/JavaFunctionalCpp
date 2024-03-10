#pragma once

#include "astnode.hpp"

class NumberNode : public AstNode
{
public:
	long number;
	NumberNode(long number);

	std::any accept(Visitor& visitor);
};
