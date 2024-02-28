#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <map>

#include "syntaxtoken.hpp"

class Lexer {
public:
	Lexer(std::string program);
	char current();
	void advance();
	SyntaxToken lex();
private:
	size_t index = 0;
	std::string program;
};


#endif // !LEXER_HPP
