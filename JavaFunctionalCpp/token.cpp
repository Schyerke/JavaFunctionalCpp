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
	case BAD_TOKEN:
		return "Bad Token";
	case END_OF_FILE_TOKEN:
		return "End Of File Token";
	default:
		return "No Token Found";
	}
	return "No Token Found";
}