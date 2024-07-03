#pragma once
#include <iostream>
#include <map>
#include "syntaxtoken.hpp"

class LexerTest;

class Lexer {
public:
	Lexer(std::string program);
	SyntaxToken lex();
private:
	char current();
	char peekNext();
	char lookAhead(int offset);
	void advance();
	int index = 0;
	std::string program;

	unsigned int row = 0;
};


