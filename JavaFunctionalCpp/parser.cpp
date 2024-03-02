
#include <iostream>
#include <vector>
#include <string>

#include "syntaxtoken.hpp"
#include "token.hpp"

#include "astnode.hpp"
#include "binaryexpression.hpp"
#include "numbernode.hpp"
#include "unarynode.hpp"

#include "printstmtnode.hpp"
#include "expressionstmtnode.hpp"

#include "parser.hpp"

Parser::Parser(std::string program)
{
	Lexer lexer(program);

	std::vector<SyntaxToken> tokens;
	//temp token, it will be overwritten.
	SyntaxToken token = SyntaxToken::SyntaxToken(NO_OPERATOR_TOKEN, "", 0, 0);
	while (token.get_token_t() != BAD_TOKEN)
	{
		token = lexer.lex();
		if (token.get_token_t() == END_OF_FILE_TOKEN)
		{
			break;
		}
		tokens.push_back(token);
	}
	this->tokens = tokens;
	this->index = 0;
}

SyntaxToken Parser::next_token()
{
	size_t size = this->tokens.size();
	if (this->index < size)
	{
		return this->tokens[this->index++];
	}
	return SyntaxToken::SyntaxToken(END_OF_FILE_TOKEN, "", this->index-1, 0);
}

void Parser::advance()
{
	size_t size = this->tokens.size();
	if (this->index < size)
	{
		this->index++;
	}
}

SyntaxToken Parser::peekNext() {
	return lookAhead(1);
}

SyntaxToken Parser::peek()
{
	return lookAhead(0);
}

SyntaxToken Parser::lookAhead(int offset) {
	size_t index = offset + this->index;
	if (index < this->tokens.size()) {
		return this->tokens[index];
	}
	return SyntaxToken::SyntaxToken(END_OF_FILE_TOKEN, "", this->index, 0);
}

SyntaxToken Parser::expect(Token_t expect)
{
	if (peek().get_token_t() == expect)
	{
		return next_token();
	}
	std::cout << "Unexpected token. Expected " << token_name(expect) << "." << std::endl;
	return SyntaxToken::SyntaxToken(BAD_TOKEN, "", -1, 0);
}

bool Parser::match(Token_t match) {
	if (peek().get_token_t() == match) {
		return true;
	}
	return false;
}

AstNode* Parser::parse()
{
	return parseStatement();
}

AstNode* Parser::parseStatement()
{
	if (match(PRINT_STMT))
	{
		return parsePrintStatement();
	}

	return parseExpressionStatement();
}

AstNode* Parser::parsePrintStatement()
{
	advance();
	AstNode* expression = parseExpression();
	expect(SEMICOLON);
	return new PrintStmtNode(expression);
}

AstNode* Parser::parseExpressionStatement()
{
	AstNode* expression = parseExpression();
	expect(SEMICOLON);
	return new ExpressionStmtNode(expression);
}

AstNode* Parser::parseExpression()
{
	return parseTerm();
}

AstNode* Parser::parseTerm()
{
	AstNode* left = parseFactor();
	while (match(PLUS_TOKEN) || match(MINUS_TOKEN))
	{
		SyntaxToken op = next_token();
		AstNode* right = parseFactor();
		left = new BinaryExpression(left, op.get_token_t(), right);
	}
	return left;
}

AstNode* Parser::parseFactor() 
{
	AstNode* left = parseUnary();

	while (match(STAR_TOKEN) || match(SLASH_TOKEN)) 
	{
		SyntaxToken op = next_token();
		AstNode* right = parseUnary();
		left = new BinaryExpression(left, op.get_token_t(), right);
	}

	return left;
}

AstNode* Parser::parseUnary()
{
	if (match(MINUS_TOKEN))
	{
		SyntaxToken token = next_token();
		AstNode* unary = parseUnary();
		return new UnaryNode(token.get_token_t(), unary);
	}
	return parsePrimary();
}

AstNode* Parser::parsePrimary() 
{
	SyntaxToken token = expect(NUMBER_TOKEN);
	if (token.get_token_t() == END_OF_FILE_TOKEN || token.get_token_t() == BAD_TOKEN) {
		return nullptr;
	}
	return new NumberNode(stol(token.get_value()));
}