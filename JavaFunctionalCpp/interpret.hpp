#pragma once

#include <iostream>
#include <any>
#include "visitor.hpp"
#include "astnode.hpp"
#include "token.hpp"

#include "environment.hpp"

class Interpreter : public Visitor {
public:
	Interpreter(Enviroment env);
	std::any interpret(std::unique_ptr<AstNode> root);

private:
	Enviroment env;

	std::any visitBinaryExpression(BinaryExpression& binaryExpression);
	std::any visitBoolNode(BoolNode& boolNode);
	std::any visitNumberNode(NumberNode& numberNode);
	std::any visitStringNode(StringNode& stringNode);
	std::any visitUnaryNode(UnaryNode& unaryNode);

	std::any visitExpressionStmt(ExpressionStmtNode& expressionStmtNode);
	std::any visitPrintStmt(PrintStmtNode& printStmtNode);
	std::any visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode);

	template<typename T> 
	std::any eva_num(T left, Token_t op, T right);
	template<typename T>
	std::any eva_bool(T left, Token_t op, T right);
};


