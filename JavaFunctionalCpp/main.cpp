#include <iostream>
#include <vector>

#include "lexer.hpp"

using namespace std;

void print_tokens(std::vector<SyntaxToken> tokens)
{
	for (SyntaxToken& token : tokens)
	{
		cout << token.get_token_t() << " " << token.get_value() << endl;
	}
}

int main() {
	string program = "1 + 2 - 3";
	Lexer lexer(program);

	std::vector<SyntaxToken> tokens;

	while (true)
	{
		SyntaxToken token = lexer.lex();
		if (token.get_token_t() == BAD_TOKEN || token.get_token_t() == END_OF_FILE_TOKEN)
		{
			break;
		}
		tokens.push_back(token);
	}
	
	print_tokens(tokens);

	return 0;
}