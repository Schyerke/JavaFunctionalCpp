

#include "lexer.hpp"
#include "syntaxtoken.hpp"
#include <iostream>
#include <map>

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
		return SyntaxToken(END_OF_FILE_TOKEN, "", this->index, 0, this->row);
	}
	while (current() == '\n')
	{
		this->row++;
		advance();
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
		if (current() == '.')
		{
			advance();
			while (isdigit(current()))
			{
				advance();
			}
		}
		size_t length = this->index - start;
		std::string text = this->program.substr(start, length);
		return SyntaxToken(NUMBER_TOKEN, text, start, this->row, length);
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
			return SyntaxToken(PRINT_STMT, "", start, this->row, length);
		}
		if (text == display_stmts(FALSE_TOKEN))
		{
			return SyntaxToken(FALSE_TOKEN, display_stmts(FALSE_TOKEN), start, this->row, length);
		}
		if (text == display_stmts(TRUE_TOKEN))
		{
			return SyntaxToken(TRUE_TOKEN, display_stmts(TRUE_TOKEN), start, this->row, length);
		}

		if (text == display_vartype(BOOL_TYPE))
		{
			return SyntaxToken(BOOL_TYPE, display_vartype(BOOL_TYPE), start, this->row, length);
		}
		if (text == display_vartype(SHORT_TYPE))
		{
			return SyntaxToken(SHORT_TYPE, display_vartype(SHORT_TYPE), start, this->row, length);
		}
		if (text == display_vartype(INT_TYPE))
		{
			return SyntaxToken(INT_TYPE, display_vartype(INT_TYPE), start, this->row, length);
		}
		if (text == display_vartype(LONG_TYPE))
		{
			return SyntaxToken(LONG_TYPE, display_vartype(LONG_TYPE), start, this->row, length);
		}
		if (text == display_vartype(FLOAT_TYPE))
		{
			return SyntaxToken(FLOAT_TYPE, display_vartype(FLOAT_TYPE), start, this->row, length);
		}
		if (text == display_vartype(DOUBLE_TYPE))
		{
			return SyntaxToken(DOUBLE_TYPE, display_vartype(DOUBLE_TYPE), start, this->row, length);
		}

		if (text == display_keyword(IF_KW))
		{
			return SyntaxToken(IF_KW, display_keyword(IF_KW), start, this->row, length);
		}
		if (text == display_keyword(RETURN_KW))
		{
			return SyntaxToken(RETURN_KW, display_keyword(RETURN_KW), start, this->row, length);
		}

		return SyntaxToken(IDENTIFIER_TOKEN, text, start, this->row, length);
	}

	switch (current())
	{
	case '+':
		if (peekNext() == '+' && lookAhead(2) == '+')
		{
			this->index += 3;
			return SyntaxToken(TRIPLE_PLUS_TOKEN, "+++", this->index - 3, 3, this->row);
		}
		if (peekNext() == '+')
		{
			this->index += 2;
			return SyntaxToken(PLUS_PLUS_TOKEN, "++", this->index - 2, this->row, 2);
		}
		if (peekNext() == '=')
		{
			this->index += 2;
			return SyntaxToken(PLUS_EQUAL_TOKEN, "+=", this->index - 2, this->row, 2);
		}
		return SyntaxToken(PLUS_TOKEN, "+", this->index++, this->row, 1);
	case '-':
		if (peekNext() == '-')
		{
			this->index += 2;
			return SyntaxToken(MINUS_MINUS_TOKEN, "--", this->index - 2, this->row, 2);
		}
		if (peekNext() == '=')
		{
			this->index += 2;
			return SyntaxToken(MINUS_EQUAL_TOKEN, "-=", this->index - 2, this->row, 2);
		}
		return SyntaxToken(MINUS_TOKEN, "-", this->index++, this->row, 1);
	case '*':
		if (peekNext() == '=')
		{
			this->index += 2;
			return SyntaxToken(STAR_EQUAL_TOKEN, "*=", this->index - 2, this->row, 2);
		}
		return SyntaxToken(STAR_TOKEN, "*", this->index++, this->row, 1);
	case '/':
		if (peekNext() == '=')
		{
			this->index += 2;
			return SyntaxToken(SLASH_EQUAL_TOKEN, "/=", this->index - 2, this->row, 2);
		}
		if (peekNext() == '*')
		{
			advance();
			advance();

			while (current() != '*' || peekNext() != '/')
			{
				advance();
			}
			advance();
			advance();
			return lex();
		}
		return SyntaxToken(SLASH_TOKEN, "/", this->index++, this->row, 1);

	case ',':
		return SyntaxToken(COMMA_TOKEN, ",", this->index++, this->row, 1);

	case '(':
		return SyntaxToken(OPEN_PAREN, "(", this->index++, this->row, 1);
	case ')':
		return SyntaxToken(CLOSE_PAREN, ")", this->index++, this->row, 1);
	case '{':
		return SyntaxToken(OPEN_CURLY_BRACKET, "{", this->index++, this->row, 1);
	case '}':
		return SyntaxToken(CLOSE_CURLY_BRACKET, "}", this->index++, this->row, 1);

	case '=':
		if (peekNext() == '=')
		{
			this->index += 2;
			return SyntaxToken(EQUAL_EQUAL_TOKEN, "==", this->index - 2, this->row, 2);
		}
		return SyntaxToken(EQUAL_TOKEN, "=", this->index++, this->row, 1);
	case '!':
		if (peekNext() == '=')
		{
			this->index += 2;
			return SyntaxToken(BANG_EQUAL_TOKEN, "!=", this->index - 2, this->row, 2);
		}
		break;
	case '&':
		if (peekNext() == '&')
		{
			this->index += 2;
			return SyntaxToken(AMPERSAND_AMPERSAND_TOKEN, "&&", this->index - 2, this->row, 2);
		}
		break;
	case '|':
		if (peekNext() == '|')
		{
			this->index += 2;
			return SyntaxToken(PIPE_PIPE_TOKEN, "||", this->index - 2, this->row, 2);
		}
		break;

	case '"':
	{
		advance();
		size_t start = this->index;
		while (current() != '"')
		{
			advance();
		}
		size_t length = this->index - start;
		std::string text = this->program.substr(start, length);
		advance(); // deleting the last "
		return SyntaxToken(STRING_LITERAL_TOKEN, text, start, this->row, length);
	}
		break;
	case ';':
		return SyntaxToken(SEMICOLON_TOKEN, ";", this->index++, this->row, 1);
	default:
		return SyntaxToken(BAD_TOKEN, "", this->index++, 0, this->row);
	}
	return SyntaxToken(BAD_TOKEN, "", this->index++, 0, this->row);
}