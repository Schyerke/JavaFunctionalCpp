#ifndef SYNTAXTOKEN_HPP
#define SYNTAXTOKEN_HPP

#include <iostream>

#include "token.hpp"

class SyntaxToken
{
public:
	SyntaxToken(Token_t token_t, std::string value, size_t pos, size_t len = -1);
	Token_t get_token_t();
	std::string get_value();
	size_t get_pos();
	size_t get_len();
private:
	Token_t token_t;
	std::string value;
	size_t pos;
	size_t len;
};

#endif // !SYNTAXTOKEN_HPP
