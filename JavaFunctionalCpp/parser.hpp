#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include "lexer.hpp"
#include "astnode.hpp"

class Parser
{
public:
	std::vector<SyntaxToken> tokens;
	size_t index;

	Parser(std::string program);

	std::unique_ptr<AstNode> parse();
private:
	SyntaxToken next_token();
	void advance();
	SyntaxToken peekNext();
	SyntaxToken peek();
	SyntaxToken expect(Token_t match);
	bool match(Token_t match);
	bool matchany(std::vector<Token_t> tokens);
	SyntaxToken lookAhead(int offset);
	std::unique_ptr<AstNode> parseStatement();
	std::unique_ptr<AstNode> parsePrintStatement();
	std::unique_ptr<AstNode> varDeclearationStatement();
	std::unique_ptr<AstNode> parseExpressionStatement();
	std::unique_ptr<AstNode> parseExpression();
	std::unique_ptr<AstNode> parseTerm();
	std::unique_ptr<AstNode> parseFactor();
	std::unique_ptr<AstNode> parseUnary();
	std::unique_ptr<AstNode> parsePrimary();
};

#endif // !PARSER_HPP
