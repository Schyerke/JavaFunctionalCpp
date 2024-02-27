#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <map>

enum Token_t
{
	NUMBER_TOKEN,
	NO_OPERATOR_TOKEN,
	PLUS_TOKEN,
	MINUS_TOKEN,

	BAD_TOKEN,
	END_OF_FILE_TOKEN
};

std::string token_name(Token_t token);

class SyntaxToken
{
public:
	SyntaxToken(Token_t token_t, std::string value, size_t pos, size_t len);
	Token_t get_token_t();
	std::string get_value();
	size_t get_pos();
	size_t get_len();
private:
	Token_t token_t;
	std::string value;
	size_t pos;
	size_t len;
};

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
