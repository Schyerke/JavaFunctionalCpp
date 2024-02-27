#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include "lexer.hpp"
#include "cast.hpp"

class AstNode
{
public:
	virtual std::string get_classname() {
		std::cout << "AstNode" << std::endl;
	}
};

class NumberNode : public AstNode
{
public:
	long number;
	NumberNode(long number);

	std::string get_classname() {
		std::string classname = number + " NumberNode\n";
		return classname;
	}
};

class BinaryOperationNode : public AstNode
{
public:
	std::unique_ptr<AstNode> left;
	std::unique_ptr<AstNode> right;
	Token_t op;

	BinaryOperationNode(AstNode left, Token_t op, AstNode right);
	BinaryOperationNode(AstNode left);

	std::string get_classname() {
		std::string classname =
			"Left " + get_node_classname(left.get()) +
			" Token " + token_name(op) 
			+ " Right " + get_node_classname(right.get());
		return classname;
	}
};


class Parser
{
public:
	std::vector<SyntaxToken> tokens;
	size_t index;

	Parser(std::string program);

	AstNode parse();
private:
	SyntaxToken next_token();
	SyntaxToken peek();
	SyntaxToken match(Token_t match);
	SyntaxToken lookAtHead(int offset);
	AstNode expression();
	AstNode parseFactor();
};

#endif // !PARSER_HPP
