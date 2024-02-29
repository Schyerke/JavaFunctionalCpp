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

	BAD_TOKEN,
	END_OF_FILE_TOKEN
};

std::string token_name(Token_t token);
#endif // !TOKEN_HPP
