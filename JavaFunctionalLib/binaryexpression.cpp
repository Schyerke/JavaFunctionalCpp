#include <iostream>
#include "token.hpp"
#include "binaryexpression.hpp"

BinaryExpression::BinaryExpression(std::unique_ptr<AstNode> left, Token_t op, std::unique_ptr<AstNode> right)
{
	this->left = std::move(left);
	this->op = op;
	this->right = std::move(right);
}

BinaryExpression::BinaryExpression(std::unique_ptr<AstNode> left) {
	this->left = std::move(left);
	this->op = NO_OPERATOR_TOKEN;
}

std::any BinaryExpression::accept(Visitor& visitor)
{
	return visitor.visitBinaryExpression(*this);
}