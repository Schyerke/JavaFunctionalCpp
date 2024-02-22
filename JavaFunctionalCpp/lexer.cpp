#include <iostream>
#include "lexer.hpp"

char Lexer::current() {
	int size = this->program.size();
	if (this->index >= size) {
		return '\0';
	}
	return program[this->index];
}

void Lexer::advance() {
	int size = this->program.size();
	if (size < this->index) {
		this->index++;
	}
}

SyntaxToken Lexer::lex() {
	if (isspace(current())) {
		while (isspace(current())) {
			advance();
		}
	}
	if (isdigit(current())) {
		int start = this->index;
		while (isdigit(current())) {
			advance();
		}
		int length = this->index - start;
		std::string text = this->program.substr(start, length);
		return new SyntaxToken(NUMBER_TOKEN, text, start);
	}

}