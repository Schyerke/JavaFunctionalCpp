#include <iostream>

#include "token.hpp"
#include "astnodehelper.hpp"
#include "binaryexpression.hpp"

BinaryExpression::BinaryExpression(std::unique_ptr<AstNode> left, Token_t op, std::unique_ptr<AstNode> right)
{
	this->left = move(left);
	this->op = op;
	this->right = move(right);
}

BinaryExpression::BinaryExpression(std::unique_ptr<AstNode> left) {
	this->left = std::move(left);
	this->op = NO_OPERATOR_TOKEN;
}

std::string BinaryExpression::get_classname() {
	std::string classname = "(" + token_name(op) + ")";
	return classname;
}

std::any BinaryExpression::accept(Visitor& visitor)
{
	return visitor.visitBinaryExpression(*this);
}