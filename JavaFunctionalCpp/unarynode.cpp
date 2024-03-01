#include "unarynode.hpp"

UnaryNode::UnaryNode(AstNode* left, Token_t token)
{
	this->left.reset(left);
	this->token = token;
}
