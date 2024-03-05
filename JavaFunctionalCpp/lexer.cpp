#include <iostream>
#include <map>
#include "lexer.hpp"
#include "syntaxtoken.hpp"

Lexer::Lexer(std::string program)
{
	this->program = program;
}

char Lexer::current()
{
	return lookAhead(0);
}

char Lexer::peekNext()
{
	return lookAhead(1);
}

char Lexer::lookAhead(int offset)
{
	size_t size = this->program.size();
	size_t index = this->index + offset;
	if (index >= size)
	{
		return '\0';
	}
	return program[index];
}

void Lexer::advance()
{
	size_t size = this->program.size();
	if (this->index < size)
	{
		this->index++;
	}
}

SyntaxToken Lexer::lex() 
{
	if (current() == '\0')
	{
		return SyntaxToken::SyntaxToken(END_OF_FILE_TOKEN, "", this->index, 0);
	}
	if (isspace(current())) 
	{
		while (isspace(current())) 
		{
			advance();
		}
	}
	if (isdigit(current()))
	{
		size_t start = this->index;
		while (isdigit(current())) 
		{
			advance();
		}
		size_t length = this->index - start;
		std::string text = this->program.substr(start, length);
		return SyntaxToken::SyntaxToken(NUMBER_TOKEN, text, start, length);
	}
	if (isalpha(current()))
	{
		size_t start = this->index;
		while (isalpha(current()))
		{
			advance();
		}
		size_t length = this->index - start;
		std::string text = this->program.substr(start, length);
		if (text == display_stmts(PRINT_STMT))
		{
			return SyntaxToken::SyntaxToken(PRINT_STMT, "", start);
		}
		if (text == display_stmts(FALSE_TOKEN))
		{
			return SyntaxToken::SyntaxToken(FALSE_TOKEN, display_stmts(FALSE_TOKEN), start, length);
		}
		if (text == display_stmts(TRUE_TOKEN))
		{
			return SyntaxToken::SyntaxToken(TRUE_TOKEN, display_stmts(TRUE_TOKEN), start, length);
		}

		return SyntaxToken::SyntaxToken(IDENTIFIER_TOKEN, text, start, length);
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

		case '=':
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken::SyntaxToken(EQUAL_EQUAL, "==", this->index - 2, 2);
			}
			if (isalpha(peekNext()))
			{
				advance();
				int start = this->index;
				while (isalpha(current()) && current() != '"')
				{
					advance();
				}
				int length = this->index - start;
				std::string text = this->program.substr(start, length);
				return SyntaxToken::SyntaxToken(STRING_LITERAL_TOKEN, text, start, length);
			}
			break;
		case '!':
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken::SyntaxToken(BANG_EQUAL, "!=", this->index - 2, 2);
			}
			break;
		case '&':
			if (peekNext() == '&')
			{
				this->index += 2;
				return SyntaxToken::SyntaxToken(AMPERSAND_AMPERSAND, "&&", this->index - 2, 2);
			}
			break;
		case '|':
			if (peekNext() == '|')
			{
				this->index += 2;
				return SyntaxToken::SyntaxToken(PIPE_PIPE, "||", this->index - 2, 2);
			}
			break;

		case ';':
			return SyntaxToken::SyntaxToken(SEMICOLON, ";", this->index++, 1);
		default:
			return SyntaxToken::SyntaxToken(BAD_TOKEN, "", this->index++, 0);
	}
	return SyntaxToken::SyntaxToken(BAD_TOKEN, "", this->index++, 0);
}