
#ifndef SYNTAXTOKEN_HPP
#define SYNTAXTOKEN_HPP

#include <iostream>
#include "lexer.hpp"

class SyntaxToken {
public:
	SyntaxToken(Token_t token_t, std::string value, int position);

private:
	Token_t token_t;
	std::string value;
	int position;
};

#endif // !SYNTAXTOKEN_HPP


