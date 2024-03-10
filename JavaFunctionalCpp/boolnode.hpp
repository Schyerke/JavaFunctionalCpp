#pragma once
#include "astnode.hpp"

class BoolNode : public AstNode {
public:
	bool value;
	BoolNode(bool value);
	std::any accept(Visitor& visitor);
};

