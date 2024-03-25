#pragma once

#include <iostream>
#include <any>
#include <string>
#include "token.hpp"
#include "astnode.hpp"

enum DataType
{
	DT_SHORT,
	DT_INT,
	DT_LONG,
	DT_FLOAT,
	DT_DOUBLE,

	DT_NOT_VALID
};

struct Variable
{
	DataType dtType = DT_NOT_VALID;
	std::string identifier;
	std::any value;
	
};

struct FuncVariable 
{
	DataType return_type = DT_NOT_VALID;
	std::string identifier;
	std::shared_ptr<AstNode> block_stmt;
};

DataType from_TokenT_to_DataType(Token_t token);

