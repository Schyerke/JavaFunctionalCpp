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

}