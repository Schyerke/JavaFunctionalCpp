#include <iostream>

#include "token.hpp"

std::string token_name(Token_t token) {
	switch (token) {
	case NUMBER_TOKEN:
		return "Number Token";
	case NO_OPERATOR_TOKEN:
		return "No Operator Token";
	case PLUS_TOKEN:
		return "Plus Token";
	case MINUS_TOKEN:
		return "Minus Token";
	case STAR_TOKEN:
		return "Star Token";
	case SLASH_TOKEN:
		return "Slash Token";
	case SEMICOLON:
		return "Semicolon";
	case BAD_TOKEN:
		return "Bad Token";
	case END_OF_FILE_TOKEN:
		return "End Of File Token";
	default:
		return "No Token Found";
	}
	return "No Token Found";
}

std::string display_stmts(Token_t stmt)
{
	switch (stmt)
	{
		case PRINT_STMT:
			return "print";
		case SEMICOLON:
			return ";";
			
		default:
			return "No Statement Found";
	}
	return "No Statement Found";
}