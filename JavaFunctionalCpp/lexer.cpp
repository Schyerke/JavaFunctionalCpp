#include <iostream>
#include "lexer.hpp"

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
		default:
			return SyntaxToken::SyntaxToken(BAD_TOKEN, "", this->index++, 0);
	}
	return SyntaxToken::SyntaxToken(BAD_TOKEN, "", this->index++, 0);
}


SyntaxToken::SyntaxToken(Token_t token_t, std::string value, size_t pos, size_t len)
{
	this->token_t = token_t;
	this->pos = pos;
	this->len = len;
	this->value = value;
}

Token_t SyntaxToken::get_token_t()
{
	return this->token_t;
}

std::string SyntaxToken::get_value()
{
	return this->value;
}

size_t SyntaxToken::get_pos()
{
	return this->pos;
}

size_t SyntaxToken::get_len()
{
	return this->len;
}