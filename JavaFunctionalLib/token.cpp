#include <iostream>

#include "token.hpp"

std::string token_name(Token_t token)
{
	switch (token)
	{
		case NUMBER_TOKEN:
			return "Number Token";
		case STRING_LITERAL_TOKEN:
			return "String Token";

		case PLUS_TOKEN:
			return "Plus Token";
		case MINUS_TOKEN:
			return "Minus Token";
		case STAR_TOKEN:
			return "Star Token";
		case SLASH_TOKEN:
			return "Slash Token";

		case EQUAL_TOKEN:
			return "Equal Token";
		case EQUAL_EQUAL_TOKEN:
			return "Equal Equal Token";


		case SEMICOLON_TOKEN:
			return "Semicolon Token";

		case NO_OPERATOR_TOKEN:
			return "No Operator Token";
		case BAD_TOKEN:
			return "Bad Token";
		case END_OF_FILE_TOKEN:
			return "End Of File Token";
		default:
			return "Invalid Token";
	}
	return "Invalid Token";
}

std::string display_vartype(Token_t varType)
{
	switch (varType)
	{
		case BOOL_TYPE:
			return "bool";
		case SHORT_TYPE:
			return "short";
		case INT_TYPE:
			return "int";
		case LONG_TYPE:
			return "long";
		case FLOAT_TYPE:
			return "float";
		case DOUBLE_TYPE:
			return "double";
	}
	return "Invalid Data Type";
}

std::string display_stmts(Token_t token)
{
	switch (token)
	{
		case PRINT_STMT:
			return "print";

		case FALSE_TOKEN:
			return "false";
		case TRUE_TOKEN:
			return "true";

		case EQUAL_TOKEN:
			return "=";

		case EQUAL_EQUAL_TOKEN:
			return "==";
		case BANG_EQUAL_TOKEN:
			return "!=";
		case AMPERSAND_AMPERSAND_TOKEN:
			return "&&";
		case PIPE_PIPE_TOKEN:
			return "||";

		case SEMICOLON_TOKEN:
			return ";";

		default:
			return "No Statement Found";
	}
	return "Invalid Statment";
}

std::string display_keyword(Token_t kw)
{
	switch (kw)
	{
		case IF_KW:
			return "if";
		case RETURN_KW:
			return "return";

		default:
			return "Invalid Keyword";
	}
}

unsigned short get_unary_operator_precedence(Token_t unary_op)
{
	switch (unary_op)
	{
		case PLUS_TOKEN:
		case MINUS_TOKEN:
			return 1;
	}
	return 0;
}

unsigned short get_binary_operator_precedence(Token_t binary_op)
{
	switch (binary_op)
	{
		case EQUAL_EQUAL_TOKEN:
		case BANG_EQUAL_TOKEN:
		case AMPERSAND_AMPERSAND_TOKEN:
		case PIPE_PIPE_TOKEN:
			return 2;

		case STAR_TOKEN:
		case SLASH_TOKEN:
			return 7;

		case PLUS_TOKEN:
		case MINUS_TOKEN:
			return 4;
	}
	return 0;
}