#pragma once
#include <iostream>
#include <any>
#include <string>
#include <vector>
#include "token.hpp"
#include "astnode.hpp"

enum DataType
{
	DT_BOOL,
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
	std::unique_ptr<AstNode> block_stmt;
	std::vector<Variable> parameters;
};

DataType from_TokenT_to_DataType(Token_t token);

