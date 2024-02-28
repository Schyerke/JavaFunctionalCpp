#ifndef BINARY_OPERATION_NODE_HPP
#define BINARY_OPERATION_NODE_HPP

#include <iostream>

#include "lexer.hpp"
#include "astnode.hpp"

class BinaryOperationNode : public AstNode
{
public:
	std::unique_ptr<AstNode> left;
	std::unique_ptr<AstNode> right;
	Token_t op;

	BinaryOperationNode(AstNode* left, Token_t op, AstNode* right);
	BinaryOperationNode(AstNode* left);

	std::string get_classname();
};

#endif // !BINARY_OPERATION_NODE_HPP
