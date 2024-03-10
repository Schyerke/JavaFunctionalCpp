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

	EQUAL_TOKEN,

	EQUAL_EQUAL,
	BANG_EQUAL,
	AMPERSAND_AMPERSAND,
	PIPE_PIPE,

	SEMICOLON,

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
