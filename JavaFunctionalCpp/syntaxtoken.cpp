#include <iostream>
#include "syntaxtoken.hpp"

SyntaxToken::SyntaxToken(Token_t token_t, std::string value, int position) {
	this->token_t = token_t;
	this->position = position;
	this->value = value;
}
