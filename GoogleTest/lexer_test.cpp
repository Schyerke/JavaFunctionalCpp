#include "pch.h"
#include "lexer.hpp"

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
	Lexer lexer = Lexer("");
};

TEST_F(LexerTest, FunctionDeclaration)
{
	//(int a, int b){print a + b;}f(2, 52); 
	program = "int f";
	SetUp();
	int row = 0;

	std::vector<SyntaxToken> expected_output = {
		SyntaxToken(INT_TYPE, display_vartype(INT_TYPE), 0, row, 3),
		SyntaxToken(IDENTIFIER_TOKEN, "f", 4, row, 1)
	};

	std::vector<SyntaxToken> lexer_output;
	while (true)
	{
		SyntaxToken token = lexer.lex();
		if (token.get_token_t() == END_OF_FILE_TOKEN || token.get_token_t() == BAD_TOKEN)
		{
			break;
		}
		lexer_output.push_back(token);
	}
	
	
}

