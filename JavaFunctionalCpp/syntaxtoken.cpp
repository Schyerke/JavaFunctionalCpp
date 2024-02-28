#include <iostream>

#include "token.hpp"
#include "syntaxtoken.hpp"



SyntaxToken::SyntaxToken(Token_t token_t, std::string value, size_t pos, size_t len)
{
	this->token_t = token_t;
	this->pos = pos;
	this->len = len;
	this->value = value;
}

Token_t SyntaxToken::get_token_t()
{
	return this->token_t;
}

std::string SyntaxToken::get_value()
{
	return this->value;
}

size_t SyntaxToken::get_pos()
{
	return this->pos;
}

size_t SyntaxToken::get_len()
{
	return this->len;
}
