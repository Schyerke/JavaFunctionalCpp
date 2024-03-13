#pragma once

#include <iostream>
#include <vector>
#include <optional>

#include "lexer.hpp"
#include "astnode.hpp"

class Parser
{
public:
	std::vector<SyntaxToken> tokens;
	size_t index;

	Parser(std::string program);

	std::vector<std::unique_ptr<AstNode>> parse();
	std::vector<std::string> get_error_reports();
private:
	void report(std::string error);
	std::vector<std::string> error_reports;

	SyntaxToken next_token();
	bool isAtEnd();
	void advance();
	SyntaxToken peekNext();
	SyntaxToken peek();
	SyntaxToken expect(Token_t match);
	std::optional<SyntaxToken> expect_optional(Token_t expect);
	bool match(Token_t match);
	bool matchany(std::vector<Token_t> tokens);
	SyntaxToken lookAhead(int offset);
	std::unique_ptr<AstNode> parseStatement();
	std::unique_ptr<AstNode> parsePrintStatement();
	std::unique_ptr<AstNode> varDeclearationStatement();
	std::unique_ptr<AstNode> varAssignmentStatement();
	std::unique_ptr<AstNode> parseExpressionStatement();
	std::unique_ptr<AstNode> parseExpression();
	std::unique_ptr<AstNode> parseTerm();
	std::unique_ptr<AstNode> parseFactor();
	std::unique_ptr<AstNode> parseUnary();
	std::unique_ptr<AstNode> parsePrimary();

	
};

