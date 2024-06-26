
#pragma once

#include "visitor.hpp"

#include "astnode.hpp"

class Traverse : public Visitor
{
public:
	void traverse(std::unique_ptr<AstNode>& statement);

private:
	std::any visitBinaryExpression(BinaryExpression& binaryExpression);
	std::any visitBoolNode(BoolNode& boolNode);
	std::any visitNumberNode(NumberNode& numberNode);
	std::any visitStringNode(StringNode& stringNode);
	std::any visitIdentifierNode(IdentifierNode& identifierNode);
	std::any visitUnaryNode(UnaryNode& unaryNode);

	std::any visitIfStmtNode(IfStmtNode& ifStmtNode);
	std::any visitPrintStmt(PrintStmtNode& printStmtNode);
	std::any visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode);
	std::any visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode);

	std::any visitFunctionCallNode(FunctionCallExpr& functionCallExpr);
	std::any visitBlockStmtNode(BlockStmtNode& blockStmtNode);
};