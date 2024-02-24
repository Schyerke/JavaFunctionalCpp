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

	Parser(std::string program);
	
	AstNode parse();
private:
	SyntaxToken next_token();
	SyntaxToken peek();
	SyntaxToken match(Token_t match);
	SyntaxToken peek();
	SyntaxToken lookAtHead(int offset);
	AstNode expression();
	AstNode parseFactor();
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
	Token_t op;

	BinaryOperationNode(AstNode left, Token_t op, AstNode right);
	BinaryOperationNode(AstNode left);
};


#endif // !PARSER_HPP
