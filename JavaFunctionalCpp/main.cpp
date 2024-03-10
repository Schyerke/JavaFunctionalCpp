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

auto read_file(std::string_view path) -> std::string
{
	constexpr auto read_size = std::size_t(4096);
	auto stream = std::ifstream(path.data());
	stream.exceptions(std::ios_base::badbit);

	if (not stream)
	{
		throw std::ios_base::failure("file does not exist");
	}

	auto out = std::string();
	auto buf = std::string(read_size, '\0');
	while (stream.read(&buf[0], read_size))
	{
		out.append(buf, 0, stream.gcount());
	}
	out.append(buf, 0, stream.gcount());
	return out;
}

int main() {
	std::string program = read_file("main.jpp");

	Parser parser(program);
	std::vector<std::unique_ptr<AstNode>> statements = std::move(parser.parse());

	Enviroment env;
	Interpreter interpreter(env);
	for (std::unique_ptr<AstNode>& stmt : statements)
	{
		interpreter.interpret(std::move(stmt));
	}
	
	return 0;
}