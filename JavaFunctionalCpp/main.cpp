#include <iostream>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"

using namespace std;

void print_tokens(std::vector<SyntaxToken> tokens)
{
	for (SyntaxToken& token : tokens)
	{
		cout << token.get_token_t() << " " << token.get_value() << endl;
	}
}

void prettyPrint(AstNode node) {
	if (node == nullptr)
	{
		return;
	}

	

}
int main() {
	string program = "1 + 2 - 3";
	
	Parser parser(program);
	AstNode root = parser.parse();

	prettyPrint(root);


	return 0;
}