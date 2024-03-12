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
		return SyntaxToken(END_OF_FILE_TOKEN, "", this->index, 0);
	}
	while (isspace(current()))
	{
		advance();
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
		return SyntaxToken(NUMBER_TOKEN, text, start, length);
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
			return SyntaxToken(PRINT_STMT, "", start);
		}
		
		if (text == display_stmts(FALSE_TOKEN))
		{
			return SyntaxToken(FALSE_TOKEN, display_stmts(FALSE_TOKEN), start, length);
		}
		if (text == display_stmts(TRUE_TOKEN))
		{
			return SyntaxToken(TRUE_TOKEN, display_stmts(TRUE_TOKEN), start, length);
		}

		if (text == display_vartype(INT_TYPE))
		{
			return SyntaxToken(INT_TYPE, display_vartype(INT_TYPE), start, length);
		}

		return SyntaxToken(IDENTIFIER_TOKEN, text, start, length);
	}

	switch (current())
	{
		case '+':
			if (peekNext() == '+')
			{
				this->index += 2;
				return SyntaxToken(PLUS_PLUS_TOKEN, "++", this->index - 2, 2);
			}
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken(PLUS_EQUAL, "+=", this->index - 2, 2);
			}
			return SyntaxToken(PLUS_TOKEN, "+", this->index++, 1);
		case '-':
			if (peekNext() == '-')
			{
				this->index += 2;
				return SyntaxToken(MINUS_MINUS_TOKEN, "--", this->index - 2, 2);
			}
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken(MINUS_EQUAL, "-=", this->index - 2, 2);
			}
			return SyntaxToken(MINUS_TOKEN, "-", this->index++, 1);
		case '*':
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken(STAR_EQUAL, "*=", this->index - 2, 2);
			}
			return SyntaxToken(STAR_TOKEN, "*", this->index++, 1);
		case '/':
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken(SLASH_EQUAL, "/=", this->index - 2, 2);
			}
			return SyntaxToken(SLASH_TOKEN, "/", this->index++, 1);

		case '=':
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken(EQUAL_EQUAL, "==", this->index - 2, 2);
			}
			return SyntaxToken(EQUAL_TOKEN, "=", this->index++, 1);
		case '!':
			if (peekNext() == '=')
			{
				this->index += 2;
				return SyntaxToken(BANG_EQUAL, "!=", this->index - 2, 2);
			}
			break;
		case '&':
			if (peekNext() == '&')
			{
				this->index += 2;
				return SyntaxToken(AMPERSAND_AMPERSAND, "&&", this->index - 2, 2);
			}
			break;
		case '|':
			if (peekNext() == '|')
			{
				this->index += 2;
				return SyntaxToken(PIPE_PIPE, "||", this->index - 2, 2);
			}
			break;

		case '"':
			if (isalpha(peekNext()) || peekNext() == '"')
			{
				advance();
				size_t start = this->index;
				while ((isalpha(current()) || isspace(current())) && current() != '"')
				{
					advance();
				}
				size_t length = this->index - start;
				std::string text = this->program.substr(start, length);
				advance(); // deleting the last "
				return SyntaxToken(STRING_LITERAL_TOKEN, text, start, length);
			}
			break;
		case ';':
			return SyntaxToken(SEMICOLON, ";", this->index++, 1);
		default:
			return SyntaxToken(BAD_TOKEN, "", this->index++, 0);
	}
	return SyntaxToken(BAD_TOKEN, "", this->index++, 0);
}