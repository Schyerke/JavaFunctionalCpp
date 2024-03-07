#include "unarynode.hpp"
#include "astnodehelper.hpp"

UnaryNode::UnaryNode(Token_t token, std::unique_ptr<AstNode> left)
{
	this->token = token;
	this->left = std::move(left);
}

std::string UnaryNode::get_classname()
{
	return "(" + token_name(this->token) + " " + get_node_classname(this->left.get()) + ")";
}
