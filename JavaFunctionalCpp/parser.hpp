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
	SyntaxToken next_token();
	SyntaxToken peekNext();
	SyntaxToken peek();
	SyntaxToken expect(Token_t match);
	bool match(Token_t match);
	SyntaxToken lookAhead(int offset);
	AstNode* parseTerm();
	AstNode* parseFactor();
	AstNode* parseNumber();
};

#endif // !PARSER_HPP
