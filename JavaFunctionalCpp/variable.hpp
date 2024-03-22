#pragma once

#include <iostream>
#include <any>
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
	bool callable = false;

	std::unique_ptr<AstNode> get_blockstmt()
	{
		if (callable)
		{
			return std::move(this->blockstmt);
		}
		return nullptr; // can't return a block statmenet if the variable isn't callable
	}
	void set_blockstmt(std::unique_ptr<AstNode> blockstmt)
	{
		if (callable)
		{
			this->blockstmt = std::move(blockstmt);
			return;
		}
		throw std::invalid_argument("Assigning a Block Statment to a non callable variable???");
	}
private:
	std::unique_ptr<AstNode> blockstmt = nullptr;
};

DataType from_TokenT_to_DataType(Token_t token);

