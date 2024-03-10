#ifndef INTERPRET_HPP
#define INTERPRET_HPP

#include <iostream>
#include <any>
#include "visitor.hpp"
#include "astnode.hpp"
#include "token.hpp"

class Interpreter : public Visitor {
public:
	std::any interpret(std::unique_ptr<AstNode> root);

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



#endif // !INTERPRET_HPP
