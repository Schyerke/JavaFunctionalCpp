#include "unarynode.hpp"
#include "astnodehelper.hpp"

UnaryNode::UnaryNode(Token_t token, AstNode* left)
{
	this->token = token;
	this->left.reset(left);
}

std::string UnaryNode::get_classname()
{
	return "(" + token_name(this->token) + " " + get_node_classname(this->left.get()) + ")";
}
