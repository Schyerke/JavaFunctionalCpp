#pragma once

#include "astnode.hpp"

enum AssignmentType
{
	AT_PLUS_PLUS,
	AT_MINUS_MINUS,
	AT_PLUS_EQUAL,
	AT_MINUS_EQUAL,
	AT_STAR_EQUAL,
	AT_SLASH_EQUAL,
	
	AT_NO_OP
};

class VarAssignmentStmtNode : public AstNode
{
public:
	std::string identifier;
	std::unique_ptr<AstNode> expression;
	AssignmentType at;

	VarAssignmentStmtNode(std::string identifier, std::unique_ptr<AstNode> expression, AssignmentType at = AT_NO_OP);
	std::any accept(Visitor& visitor);
};