
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "parser.hpp"
#include "cast.hpp"

Parser::Parser(std::string program)
{
	Lexer lexer(program);

	std::vector<SyntaxToken> tokens;

	while (true)
	{
		SyntaxToken token = lexer.lex();
		if (token.get_token_t() == BAD_TOKEN || token.get_token_t() == END_OF_FILE_TOKEN)
		{
			break;
		}
		tokens.push_back(token);
	}
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

SyntaxToken Parser::peek()
{
	return lookAtHead(0);
}

SyntaxToken Parser::lookAtHead(int offset) {
	size_t index = offset + this->index;
	if (index < this->tokens.size()) {
		return this->tokens[index];
	}
	return this->tokens[this->tokens.size() - 1];
}

SyntaxToken Parser::match(Token_t match)
{
	if (peek().get_token_t() == match)
	{
		return next_token();
	}
	std::cout << "Unexpected match" << std::endl;
	return SyntaxToken::SyntaxToken(BAD_TOKEN, "", -1, 0);
}

AstNode Parser::parse()
{
	return expression();
}

AstNode Parser::expression()
{
	AstNode left = parseFactor();
	while (peek().get_token_t() == PLUS_TOKEN || peek().get_token_t() == MINUS_TOKEN)
	{
		SyntaxToken op = next_token();
		AstNode right = parseFactor();
		left = BinaryOperationNode::BinaryOperationNode(left, op.get_token_t(), right);
	}
	return left;
}

AstNode Parser::parseFactor() 
{
	SyntaxToken token = match(NUMBER_TOKEN);
	return NumberNode::NumberNode(std::stol(token.get_value()));
}

std::string AstNode::get_classname() {
	return "AstNode";
}

NumberNode::NumberNode(long number)
{
	this->number = number;
}

std::string NumberNode::get_classname() {
	std::string classname = number + " NumberNode\n";
	return classname;
}

BinaryOperationNode::BinaryOperationNode(AstNode left, Token_t op, AstNode right)
{
	this->left = std::make_unique<AstNode>(left);
	this->op = op;
	this->right = std::make_unique<AstNode>(right);
}

BinaryOperationNode::BinaryOperationNode(AstNode left) {
	this->left = std::make_unique<AstNode>(left);
	this->op = NO_OPERATOR_TOKEN;
}

std::string BinaryOperationNode::get_classname() {
	std::string classname = "Left " + get_node_classname(left.get()) + " Token " + token_name(op) + " Right " + get_node_classname(right.get());
	return classname;
}
