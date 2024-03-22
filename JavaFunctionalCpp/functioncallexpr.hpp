#pragma once

#include "astnode.hpp"

class FunctionCallExpr : public AstNode
{
public:
	std::any accept(Visitor& visitor);

};