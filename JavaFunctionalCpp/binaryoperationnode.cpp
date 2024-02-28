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
	std::string classname = "(Left_" + get_node_classname(left.get()) + "_Token_" + token_name(op) + "_Right_" + get_node_classname(right.get()) + ")";
	classname.append("\n");
	return classname;
}
