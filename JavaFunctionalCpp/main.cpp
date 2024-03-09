#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"
#include "astnode.hpp"
#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "syntaxtoken.hpp"
#include "unarynode.hpp"

#include "interpret.hpp"

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
	if (UnaryNode* unaryNode = dynamic_cast<UnaryNode*>(node)) {
		std::cout << unaryNode->get_classname();
	}
	if (BinaryExpression* binaryExpression = dynamic_cast<BinaryExpression*>(node)) {
		prettyPrint(binaryExpression->left.get());
		std::cout << binaryExpression->get_classname();
		prettyPrint(binaryExpression->right.get());
	}
	
}

int main() {
	std::string program;

	std::ifstream srcfile("main.jpp");
	while (std::getline(srcfile, program));

	Parser parser(program);
	std::unique_ptr<AstNode> root = std::move(parser.parse());

	std::cout << std::endl;

	Interpreter interpreter;
	std::any result = interpreter.interpret(std::move(root));
	

	return 0;
}