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


void print_tokens(std::vector<SyntaxToken> tokens)
{
	for (SyntaxToken& token : tokens)
	{
		std::cout << token.get_token_t() << " " << token.get_value() << std::endl;
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
	
	std::cout << std::any_cast<long>(result);

	return 0;
}