#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include "lexer.hpp"

class Parser
{
public:
	std::vector<SyntaxToken> tokens;
	size_t index;

	Parser(std::vector<SyntaxToken> tokens);
	SyntaxToken next_token();
	SyntaxToken current();
	bool match(Token_t match);
	AstNode parse();

	AstNode expression();
};

class AstNode
{
	
};

class NumberNode : public AstNode
{
public:
	long number;
	NumberNode(long number);

};

class BinaryOperationNode : public AstNode
{
public:
	std::unique_ptr<AstNode> left;
	std::unique_ptr<AstNode> right;

	BinaryOperationNode(AstNode left, AstNode right);
};


#endif // !PARSER_HPP
