#pragma once

#include <iostream>
#include <any>
#include "visitor.hpp"
#include "astnode.hpp"
#include "token.hpp"
#include "varassignmentstmtnode.hpp"

#include "environment.hpp"

class Interpreter : public Visitor {
public:
	Interpreter(Enviroment env);
	std::any interpret(std::unique_ptr<AstNode> root);
	std::vector<std::string> get_runtime_errors();


private:
	Enviroment env;

	std::vector<std::string> runtime_errors;
	void report(std::string error);

	std::any visitBinaryExpression(BinaryExpression& binaryExpression);
	std::any visitBoolNode(BoolNode& boolNode);
	std::any visitNumberNode(NumberNode& numberNode);
	std::any visitStringNode(StringNode& stringNode);
	std::any visitIdentifierNode(IdentifierNode& identifierNode);
	std::any visitUnaryNode(UnaryNode& unaryNode);

	std::any visitPrintStmt(PrintStmtNode& printStmtNode);
	std::any visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode);
	std::any visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode);

	std::any visitFunctionStmtNode(FunctionStmtNode& functionStmtNode);
	std::any visitFunctionCallNode(FunctionCallExpr& functionCallExpr);
	std::any visitBlockStmtNode(BlockStmtNode& blockStmtNode);
};


