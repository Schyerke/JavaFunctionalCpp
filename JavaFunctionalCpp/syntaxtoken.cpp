#include <iostream>
#include "syntaxtoken.hpp"

SyntaxToken::SyntaxToken(Token_t token_t, std::string value, size_t pos, size_t len) {
	this->token_t = token_t;
	this->pos = pos;
	this->len = len;
	this->value = value;
}
