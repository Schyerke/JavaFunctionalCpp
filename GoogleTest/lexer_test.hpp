#pragma once
#include <gtest/gtest.h>

#include "../JavaFunctionalCpp/lexer.hpp"

class LexerTest : public testing::Test
{
protected:
	void SetUp() override 
	{
		lexer = Lexer(program);
	}

	void TearDown() override
	{
		
	}

	std::string program;
	Lexer lexer;
};