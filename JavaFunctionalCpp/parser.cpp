
#include <iostream>
#include <vector>
#include <string>
#include <optional>

#include "syntaxtoken.hpp"
#include "token.hpp"

#include "astnode.hpp"
#include "binaryexpression.hpp"
#include "numbernode.hpp"
#include "unarynode.hpp"
#include "boolnode.hpp"
#include "stringnode.hpp"
#include "identifiernode.hpp"
#include "vardeclarationnode.hpp"
#include "varassignmentstmtnode.hpp"

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

bool Parser::isAtEnd()
{
	if (this->index >= this->tokens.size())
	{
		return true;
	}
	return false;
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
	std::cout << "Expected " << token_name(expect) << " token"<< std::endl;
	return SyntaxToken::SyntaxToken(BAD_TOKEN, "", -1, 0);
}

std::optional<SyntaxToken> Parser::expect_optional(Token_t expect)
{
	if (peek().get_token_t() == expect)
	{
		return next_token();
	}
	return std::nullopt;
}

bool Parser::match(Token_t match) {
	if (peek().get_token_t() == match) {
		return true;
	}
	return false;
}

bool Parser::matchany(std::vector<Token_t> tokens)
{
	for (Token_t token : tokens)
	{
		if (match(token))
		{
			return true;
		}
	}
	return false;
}

std::vector<std::unique_ptr<AstNode>> Parser::parse()
{
	std::vector<std::unique_ptr<AstNode>> statements;
	while (!isAtEnd())
	{
		std::unique_ptr<AstNode> statement = parseStatement();
		statements.push_back(std::move(statement));
	}
	return statements;
}

std::unique_ptr<AstNode> Parser::parseStatement()
{
	if (match(PRINT_STMT))
	{
		return parsePrintStatement();
	}
	if (match(INT_TYPE))
	{
		return varDeclearationStatement();
	}
	if (match(IDENTIFIER_TOKEN))
	{
		return varAssignmentStatement();
	}
	return parseExpressionStatement();
}

std::unique_ptr<AstNode> Parser::parsePrintStatement()
{
	advance();
	std::unique_ptr<AstNode> expression = parseExpression();
	expect(SEMICOLON_TOKEN);
	return std::make_unique<PrintStmtNode>(std::move(expression));
}

std::unique_ptr<AstNode> Parser::varDeclearationStatement()
{
	SyntaxToken dataType = expect(INT_TYPE);
	SyntaxToken identifier = expect(IDENTIFIER_TOKEN);

	std::unique_ptr<AstNode> expression;
	if (expect_optional(EQUAL_TOKEN))
	{
		expression = std::move(parseExpression());
	}
	expect(SEMICOLON_TOKEN);
	
	return std::make_unique<VarDeclarationNode>(dataType.get_token_t(), identifier.get_value(), std::move(expression));
}

std::unique_ptr<AstNode> Parser::varAssignmentStatement()
{
	SyntaxToken identifier = expect(IDENTIFIER_TOKEN);

	if (expect_optional(PLUS_PLUS_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), PLUS_TOKEN, std::make_unique<NumberNode>(1));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}
	if (expect_optional(TRIPLE_PLUS_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), PLUS_TOKEN, std::make_unique<NumberNode>(2));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}
	if (expect_optional(MINUS_MINUS_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), MINUS_TOKEN, std::make_unique<NumberNode>(1));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}
	if (expect_optional(PLUS_EQUAL_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), PLUS_TOKEN, std::move(parseExpression()));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}
	if (expect_optional(MINUS_EQUAL_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), MINUS_TOKEN, std::move(parseExpression()));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}
	if (expect_optional(STAR_EQUAL_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), STAR_TOKEN, std::move(parseExpression()));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}
	if (expect_optional(SLASH_EQUAL_TOKEN))
	{
		std::unique_ptr<AstNode> ppt = std::make_unique<BinaryExpression>(std::make_unique<IdentifierNode>(identifier.get_value()), SLASH_TOKEN, std::move(parseExpression()));
		expect(SEMICOLON_TOKEN);
		return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(ppt));
	}

	expect(EQUAL_TOKEN);
	std::unique_ptr<AstNode> expression = parseExpression();
	expect(SEMICOLON_TOKEN);
	return std::make_unique<VarAssignmentStmtNode>(identifier.get_value(), std::move(expression));
}

std::unique_ptr<AstNode> Parser::parseExpressionStatement()
{
	std::unique_ptr<AstNode> expression = parseExpression();
	expect(SEMICOLON_TOKEN);
	return std::make_unique<ExpressionStmtNode>(std::move(expression));
}

std::unique_ptr<AstNode> Parser::parseExpression()
{
	return parseTerm();
}

std::unique_ptr<AstNode> Parser::parseTerm()
{
	std::unique_ptr<AstNode> left = parseFactor();	
	while (matchany({PLUS_TOKEN, MINUS_TOKEN, EQUAL_EQUAL_TOKEN, BANG_EQUAL_TOKEN, AMPERSAND_AMPERSAND_TOKEN, PIPE_PIPE_TOKEN}))
	{
		SyntaxToken op = next_token();
		std::unique_ptr<AstNode> right = parseFactor();
		left = std::make_unique<BinaryExpression>(std::move(left), op.get_token_t(), std::move(right));
	}
	return left;
}

std::unique_ptr<AstNode> Parser::parseFactor() 
{
	std::unique_ptr<AstNode> left = parseUnary();

	while (matchany({STAR_TOKEN, SLASH_TOKEN}))
	{
		SyntaxToken op = next_token();
		std::unique_ptr<AstNode> right = parseUnary();
		left = std::make_unique<BinaryExpression>(std::move(left), op.get_token_t(), std::move(right));
	}

	return left;
}

std::unique_ptr<AstNode> Parser::parseUnary()
{
	if (match(MINUS_TOKEN))
	{
		SyntaxToken token = next_token();
		std::unique_ptr<AstNode> unary = parseUnary();
		return std::make_unique<UnaryNode>(token.get_token_t(), std::move(unary));
	}
	return parsePrimary();
}

std::unique_ptr<AstNode> Parser::parsePrimary() 
{
	std::unique_ptr<AstNode> primary; // null pointer
	SyntaxToken token = SyntaxToken::SyntaxToken(BAD_TOKEN, "", -1);
	if (match(NUMBER_TOKEN)) {
		token = next_token();
		return std::make_unique<NumberNode>(stol(token.get_value()));
	}
	else if (match(STRING_LITERAL_TOKEN))
	{
		token = next_token();
		return std::make_unique<StringNode>(token.get_value());
	}
	else if (match(IDENTIFIER_TOKEN))
	{
		token = next_token();
		return std::make_unique<IdentifierNode>(token.get_value());
	}
	else if (match(FALSE_TOKEN)) {
		advance();
		return std::make_unique<BoolNode>(false);
	}
	else if (match(TRUE_TOKEN)) {
		advance();
		return std::make_unique<BoolNode>(true);
	}
	return primary;
}
