#include <iostream>

#include "token.hpp"
#include "astnodehelper.hpp"
#include "binaryoperationnode.hpp"

BinaryOperationNode::BinaryOperationNode(AstNode* left, Token_t op, AstNode* right)
{
	this->left.reset(left);
	this->op = op;
	this->right.reset(right);
}

BinaryOperationNode::BinaryOperationNode(AstNode* left) {
	this->left.reset(left);
	this->op = NO_OPERATOR_TOKEN;
}

std::string BinaryOperationNode::get_classname() {
	std::string classname = "(" + token_name(op) + ")";
	classname.append("\n");
	return classname;
}
