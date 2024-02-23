
#include <iostream>
#include <vector>

#include "parser.hpp"

Parser::Parser(std::vector<SyntaxToken> tokens)
{
	this->tokens = tokens;
	this->index = 0;
}

AstNode Parser::parse()
{
	return expression();
}

AstNode Parser::expression()
{
	
}