
#include <iostream>
#include <vector>
#include <string>

#include "parser.hpp"

Parser::Parser(std::vector<SyntaxToken> tokens)
{
	this->tokens = tokens;
	this->index = 0;
}

SyntaxToken Parser::next_token()
{
	size_t size = this->tokens.size();
	if (this->index < size)
	{
		return this->tokens[this->index++];
	}
	return SyntaxToken::SyntaxToken(END_OF_FILE_TOKEN, "", this->index-1, 0);
}

SyntaxToken Parser::current()
{
	return this->tokens[this->index];
}

bool Parser::match(Token_t match)
{
	if (current().get_token_t() == match)
	{
		return true;
	}
	return false;
}

AstNode Parser::parse()
{
	return expression();
}

AstNode Parser::expression()
{
	SyntaxToken left_t = next_token();
	
	while (match(PLUS_TOKEN))
	{
		left_t = next_token();

	}
}


NumberNode::NumberNode(long number)
{
	this->number = number;
}

BinaryOperationNode::BinaryOperationNode(AstNode left, AstNode right)
{
	this->left = std::make_unique<AstNode>(left);
	this->right = std::make_unique<AstNode>(right);
}