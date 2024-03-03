#include <iostream>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"
#include "astnode.hpp"
#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "syntaxtoken.hpp"
#include "unarynode.hpp"

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
	std::string program = "true==true;";
	
	Parser parser(program);
	AstNode* root = parser.parse();
	std::cout << std::endl;


	
	Evaluator* evaluator = new Evaluator();
	Result result = evaluator->evaluate(root);
	
	switch (result.resultType) {
	case NUMBER:
		std::cout << result.number << std::endl;
		break;
	case BOOLEAN:
		if (result.boolean) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
		break;
	}



	return 0;
}