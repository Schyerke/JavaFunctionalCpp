#pragma once

#include <iostream>
#include <any>
#include "token.hpp"

enum DataType
{
	DT_INT,

	DT_NOT_VALID
};

struct Variable
{
	DataType dtType = DT_NOT_VALID;
	std::string identifier;
	std::any value;
};

DataType tokent2datatype(Token_t token);

