#ifndef UNARYNODE_HPP
#define UNARYNODE_HPP

#include <iostream>

#include "astnode.hpp"
#include "token.hpp"

class UnaryNode : public AstNode {
public:
	std::unique_ptr<AstNode> left;
	Token_t token;

	UnaryNode(Token_t token, AstNode* left);
};


#endif // !UNARYNODE_HPP
