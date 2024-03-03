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

	AstNode* parse();
private:
	AstNode* parseStatement();
	AstNode* parsePrintStatement();
	AstNode* parseExpressionStatement();
	AstNode* parseExpression();
	SyntaxToken next_token();
	void advance();
	SyntaxToken peekNext();
	SyntaxToken peek();
	SyntaxToken expect(Token_t match);
	bool match(Token_t match);
	bool matchall(std::vector<Token_t> tokens);
	SyntaxToken lookAhead(int offset);
	AstNode* parseTerm();
	AstNode* parseFactor();
	AstNode* parseUnary();
	AstNode* parsePrimary();
};

#endif // !PARSER_HPP
