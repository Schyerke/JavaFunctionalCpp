#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include "syntaxtoken.hpp"

enum Token_t {
	NUMBER_TOKEN,
	PLUS_TOKEN,
	MINUS_TOKEN
};

class Lexer {
public:
	char current();
	void advance();
	SyntaxToken lex();

private:
	int index = 0;
	std::string program;
};


#endif // !LEXER_HPP
