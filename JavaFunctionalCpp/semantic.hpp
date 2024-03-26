#pragma once

#include "astnode.hpp"
#include "environment.hpp"
#include "envstack.hpp"


class Semantic : public Visitor
{
public:
	EnvStack env_stack;
	Semantic(EnvStack env);

	std::vector<std::string> analyse(std::vector<std::unique_ptr<AstNode>>& statements);


private:
	std::vector<std::string> errors;
	void add_err(std::string error);

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