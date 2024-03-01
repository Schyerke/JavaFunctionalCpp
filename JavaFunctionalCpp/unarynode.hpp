#ifndef UNARYNODE_HPP
#define UNARYNODE_HPP

#include <iostream>

#include "astnode.hpp"
#include "token.hpp"

class UnaryNode : public AstNode {
public:
	std::unique_ptr<AstNode> left;
	Token_t token;

	UnaryNode(AstNode* left, Token_t token);
};


#endif // !UNARYNODE_HPP
