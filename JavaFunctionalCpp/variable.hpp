#ifndef DATA_TYPE_HPP
#define DATA_TYPE_HPP

#include <iostream>
#include "token.hpp"

enum DataType
{
	DT_INT,

	DT_NOT_VALID
};

struct Variable
{
	DataType dtType;
	std::string identifier;
	std::string value;
};

DataType tokent2datatype(Token_t token);

#endif // !DATA_TYPE_HPP
