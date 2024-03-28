
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "functionmemory.hpp"

#include "lexer.hpp"
#include "parser.hpp"
#include "astnode.hpp"
#include "numbernode.hpp"
#include "binaryexpression.hpp"
#include "syntaxtoken.hpp"
#include "unarynode.hpp"

#include "semantic.hpp"
#include "interpret.hpp"


void print_errors(std::vector<std::string> errors)
{
	for (std::string& error : errors)
	{
		std::cout << error << std::endl;
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

int main()
{
	std::string program = read_file("main.jpp");

	EnvStack p_env;
	FunctionMemory function_memory;
	Parser parser(program, std::move(p_env), function_memory);
	std::vector<std::unique_ptr<AstNode>> statements = std::move(parser.parse());

	std::vector<std::string> error_reports = parser.get_error_reports();

	if (not error_reports.empty())
	{
		std::cout << "Parser Errors:" << std::endl;
		print_errors(error_reports);
		return 64;
	}

	EnvStack sem_env;
	Semantic semantic = Semantic(std::move(sem_env), function_memory);
	std::vector<std::string> semantic_errors = semantic.analyse(statements);
	if (not semantic_errors.empty())
	{
		std::cout << "Semantic Analysis Error:" << std::endl;
		print_errors(semantic_errors);
		return 64;
	}

	EnvStack env;
	Interpreter interpreter(std::move(env), function_memory);
	for (std::unique_ptr<AstNode>& stmt : statements)
	{
		if (stmt == nullptr)
		{
			continue;
		}
		interpreter.interpret(std::move(stmt));
		if (not interpreter.get_runtime_errors().empty())
		{
			print_errors(interpreter.get_runtime_errors());
			break;
		}
	}
	
	return 0;
}
