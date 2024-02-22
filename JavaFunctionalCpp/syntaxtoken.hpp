
#ifndef SYNTAXTOKEN_HPP
#define SYNTAXTOKEN_HPP

#include <iostream>
#include "lexer.hpp"

class SyntaxToken {
public:
	SyntaxToken(Token_t token_t, std::string value, size_t pos, size_t len);

private:
	Token_t token_t;
	std::string value;
	size_t pos;
	size_t len;
};

#endif // !SYNTAXTOKEN_HPP


