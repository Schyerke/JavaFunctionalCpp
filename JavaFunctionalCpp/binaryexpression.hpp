#ifndef BINARY_EXPRESSION_HPP
#define BINARY_EXPRESSION_HPP

#include <iostream>

#include "lexer.hpp"
#include "astnode.hpp"

class BinaryExpression : public AstNode
{
public:
	std::unique_ptr<AstNode> left;
	std::unique_ptr<AstNode> right;
	Token_t op;

	BinaryExpression(AstNode* left, Token_t op, AstNode* right);
	BinaryExpression(AstNode* left);

	std::string get_classname();
};

#endif // !BINARY_EXPRESSION_HPP
