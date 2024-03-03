#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <map>

#include "syntaxtoken.hpp"

class Lexer {
public:
	Lexer(std::string program);
	SyntaxToken lex();
private:
	char current();
	char peekNext();
	char lookAhead(int offset);
	void advance();
	size_t index = 0;
	std::string program;
};


#endif // !LEXER_HPP
