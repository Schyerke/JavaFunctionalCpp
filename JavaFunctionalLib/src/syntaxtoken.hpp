#pragma once
#include <iostream>

#include "token.hpp"

class SyntaxToken
{
public:
	SyntaxToken(Token_t token_t, std::string value, size_t pos, unsigned int row, size_t len);
	Token_t get_token_t();
	std::string get_value();
	size_t get_pos();
	unsigned int get_row();
	size_t get_len();
private:
	Token_t token_t;
	std::string value;
	size_t pos;
	unsigned int row;
	size_t len;
};

