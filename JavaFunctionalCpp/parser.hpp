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
	SyntaxToken peek();
	SyntaxToken match(Token_t match);
	SyntaxToken lookAhead(int offset);
	AstNode* expression();
	AstNode* parseFactor();
};

#endif // !PARSER_HPP
