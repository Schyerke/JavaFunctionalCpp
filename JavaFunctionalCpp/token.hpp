#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>

enum Token_t
{
	NUMBER_TOKEN,
	NO_OPERATOR_TOKEN,
	PLUS_TOKEN,
	MINUS_TOKEN,
	STAR_TOKEN,
	SLASH_TOKEN,

	EQUAL_EQUAL,
	BANG_EQUAL,
	AMPERSAND_AMPERSAND,
	PIPE_PIPE,

	FALSE_TOKEN,
	TRUE_TOKEN,

	SEMICOLON,

	//statements
	PRINT_STMT,

	BAD_TOKEN,
	END_OF_FILE_TOKEN
};

std::string token_name(Token_t token);
std::string display_stmts(Token_t stmt);

#endif // !TOKEN_HPP
