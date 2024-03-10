#pragma once

#include "astnode.hpp"

class ExpressionStmtNode : public AstNode
{
public:
	std::unique_ptr<AstNode> expression;

	ExpressionStmtNode(std::unique_ptr<AstNode> expression);
	std::any accept(Visitor& visitor);
};


