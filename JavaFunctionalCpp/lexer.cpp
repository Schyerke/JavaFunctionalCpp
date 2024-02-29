#include <iostream>
#include <map>
#include "lexer.hpp"
#include "syntaxtoken.hpp"

Lexer::Lexer(std::string program)
{
	this->program = program;
}

char Lexer::current() {
	size_t size = this->program.size();
	if (this->index >= size) {
		return '\0';
	}
	return program[this->index];
}

void Lexer::advance() {
	size_t size = this->program.size();
	if (this->index < size)
	{
		this->index++;
	}
}

SyntaxToken Lexer::lex() {
	if (current() == '\0')
	{
		return SyntaxToken::SyntaxToken(END_OF_FILE_TOKEN, "", this->index, 0);
	}
	if (isspace(current())) {
		while (isspace(current())) {
			advance();
		}
	}
	if (isdigit(current())) {
		size_t start = this->index;
		while (isdigit(current())) {
			advance();
		}
		size_t length = this->index - start;
		std::string text = this->program.substr(start, length);
		return SyntaxToken::SyntaxToken(NUMBER_TOKEN, text, start, length);
	}

	switch (current())
	{
		case '+':
			return SyntaxToken::SyntaxToken(PLUS_TOKEN, "+", this->index++, 1);
		case '-':
			return SyntaxToken::SyntaxToken(MINUS_TOKEN, "-", this->index++, 1);
		case '*':
			return SyntaxToken::SyntaxToken(STAR_TOKEN, "*", this->index++, 1);
		case '/':
			return SyntaxToken::SyntaxToken(SLASH_TOKEN, "/", this->index++, 1);
		default:
			return SyntaxToken::SyntaxToken(BAD_TOKEN, "", this->index++, 0);
	}
	return SyntaxToken::SyntaxToken(BAD_TOKEN, "", this->index++, 0);
}