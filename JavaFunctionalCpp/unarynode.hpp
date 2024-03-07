#ifndef UNARYNODE_HPP
#define UNARYNODE_HPP

#include <iostream>

#include "astnode.hpp"
#include "token.hpp"

class UnaryNode : public AstNode {
public:
	UnaryNode(Token_t token, std::unique_ptr<AstNode> left);

	std::string get_classname();

	std::unique_ptr<AstNode> left;
	Token_t token;

};


#endif // !UNARYNODE_HPP
