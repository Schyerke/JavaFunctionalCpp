#pragma once

#include <iostream>

enum Token_t
{
	NUMBER_TOKEN,
	STRING_LITERAL_TOKEN, // something like "hello world" (with "")
	IDENTIFIER_TOKEN,
	FALSE_TOKEN,
	TRUE_TOKEN,

	NO_OPERATOR_TOKEN,
	PLUS_TOKEN,
	MINUS_TOKEN,
	STAR_TOKEN,
	SLASH_TOKEN,

	PLUS_PLUS_TOKEN,
	TRIPLE_PLUS_TOKEN,
	MINUS_MINUS_TOKEN,
	PLUS_EQUAL_TOKEN,
	MINUS_EQUAL_TOKEN,
	STAR_EQUAL_TOKEN,
	SLASH_EQUAL_TOKEN,

	EQUAL_TOKEN,

	EQUAL_EQUAL_TOKEN,
	BANG_EQUAL_TOKEN,
	AMPERSAND_AMPERSAND_TOKEN,
	PIPE_PIPE_TOKEN,

	SEMICOLON_TOKEN,

	//variable types
	INT_TYPE,

	//statements
	PRINT_STMT,

	BAD_TOKEN,
	END_OF_FILE_TOKEN
};

std::string token_name(Token_t token);
std::string display_vartype(Token_t varType);
std::string display_stmts(Token_t stmt);
