#pragma once

#include "visitor.hpp"

class AstNode
{
public:
	virtual	std::any accept(Visitor& visitor) = 0;
};

