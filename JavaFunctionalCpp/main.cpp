#include <iostream>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"
#include "astnode.hpp"
#include "numbernode.hpp"
#include "binaryoperationnode.hpp"
#include "syntaxtoken.hpp"
#include "evaluator.hpp"

void print_tokens(std::vector<SyntaxToken> tokens)
{
	for (SyntaxToken& token : tokens)
	{
		std::cout << token.get_token_t() << " " << token.get_value() << std::endl;
	}
}

void prettyPrint(AstNode* node) {
	if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node)) {
		std::cout << numberNode->get_classname();
	}
	if (BinaryOperationNode* binaryOperationNode = dynamic_cast<BinaryOperationNode*>(node)) {
		prettyPrint(binaryOperationNode->left.get());
		std::cout << binaryOperationNode->get_classname();
		prettyPrint(binaryOperationNode->right.get());
	}
	
}

int main() {
	std::string program = "1 + 3 / 3";
	
	Parser parser(program);
	AstNode* root = parser.parse();
	std::cout << std::endl;

	prettyPrint(root);

	/*
	Evaluator* evaluator = new Evaluator();
	long result = evaluator->evaluate(root);
	std::cout << std::endl;
	std::cout << "Result: " << result;*/

	return 0;
}