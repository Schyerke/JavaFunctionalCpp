#include <iostream>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"
#include "cast.hpp"

using namespace std;

void print_tokens(std::vector<SyntaxToken> tokens)
{
	for (SyntaxToken& token : tokens)
	{
		cout << token.get_token_t() << " " << token.get_value() << endl;
	}
}

void prettyPrint(AstNode* node) {
	if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node)) {
		cout << numberNode->get_classname();
	}
	if (BinaryOperationNode* binaryOperationNode = dynamic_cast<BinaryOperationNode*>(node)) {
		prettyPrint(binaryOperationNode->left.get());
		cout << binaryOperationNode->get_classname();
		prettyPrint(binaryOperationNode->right.get());
	}
}
int main() {
	string program = "1 + 2 - 3";
	
	Parser parser(program);
	AstNode root = parser.parse();

	prettyPrint(&root);


	return 0;
}