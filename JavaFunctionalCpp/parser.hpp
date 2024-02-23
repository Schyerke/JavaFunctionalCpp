#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include "lexer.hpp"

class Parser
{
public:
	std::vector<SyntaxToken> tokens;
	size_t index;

	Parser(std::vector<SyntaxToken> tokens);
	AstNode parse();


	
};

class AstNode
{
	
};

class NumberNode : public AstNode
{
	long number;
};

class BinaryOperationNode : public AstNode
{
	std::unique_ptr<AstNode> left;
	std::unique_ptr<AstNode> right;
};

class AdditionNode : public BinaryOperationNode
{

};


#endif // !PARSER_HPP
