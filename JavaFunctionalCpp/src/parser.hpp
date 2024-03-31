#pragma once

#include <iostream>
#include <vector>
#include <optional>

#include "lexer.hpp"
#include "astnode.hpp"
#include "environment.hpp"
#include "envstack.hpp"

#include "functionmemory.hpp"

class Parser
{
public:
	Parser(std::string program, EnvStack env, FunctionMemory& function_memory);

	std::vector<std::unique_ptr<AstNode>> parse();
	std::vector<std::string> get_error_reports();
private:
	EnvStack env_stack;
	FunctionMemory& function_memory;
	std::vector<SyntaxToken> tokens;
	int index;

	void report(std::string error);
	std::vector<std::string> error_reports;


	SyntaxToken next_token();
	bool is_at_end();
	void advance();
	SyntaxToken peek_next_next();
	SyntaxToken peek_next();
	SyntaxToken peek();
	SyntaxToken previous();
	SyntaxToken previous_previous();
	SyntaxToken expect(Token_t match);
	std::optional<SyntaxToken> expect_optional(Token_t expect);
	std::optional<SyntaxToken> find_var_type();
	bool match(Token_t match);
	bool matchany(std::vector<Token_t> tokens);
	SyntaxToken look_ahead(int offset);
	std::unique_ptr<AstNode> parseStatement();
	std::unique_ptr<AstNode> parsePrintStatement();
	std::unique_ptr<AstNode> declarationStatement();
	std::unique_ptr<AstNode> functionDeclarationStatement();
	std::unique_ptr<AstNode> functionCall();
	std::vector<Variable> parameters();
	std::vector<std::unique_ptr<AstNode>> arguments();
	std::unique_ptr<AstNode> blockStatement(std::vector<Variable> pre_vars, std::string func_id);
	std::unique_ptr<AstNode> varDeclarationStatement();
	std::unique_ptr<AstNode> varAssignmentStatement();
	std::unique_ptr<AstNode> parseExpression();
	std::unique_ptr<AstNode> parseTerm();
	std::unique_ptr<AstNode> parseFactor();
	std::unique_ptr<AstNode> parseUnary();
	std::unique_ptr<AstNode> parsePrimary();

};

