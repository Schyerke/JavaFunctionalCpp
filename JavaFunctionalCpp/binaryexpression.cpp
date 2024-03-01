#include <iostream>

#include "token.hpp"
#include "astnodehelper.hpp"
#include "binaryexpression.hpp"

BinaryExpression::BinaryExpression(AstNode* left, Token_t op, AstNode* right)
{
	this->left.reset(left);
	this->op = op;
	this->right.reset(right);
}

BinaryExpression::BinaryExpression(AstNode* left) {
	this->left.reset(left);
	this->op = NO_OPERATOR_TOKEN;
}

std::string BinaryExpression::get_classname() {
	std::string classname = "(" + token_name(op) + ")";
	return classname;
}
