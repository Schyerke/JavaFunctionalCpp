#pragma once

#include <any>
#include <iostream>

class BinaryExpression;
class BoolNode;
class NumberNode;
class StringNode;
class IdentifierNode;
class UnaryNode;

class ExpressionStmtNode;
class PrintStmtNode;
class VarDeclarationNode;
class VarAssignmentStmtNode;

class FunctionStmtNode;
class BlockStmtNode;

class Visitor {
public:
	virtual std::any visitBinaryExpression(BinaryExpression& binaryExpression) = 0;
	virtual std::any visitBoolNode(BoolNode& boolNode) = 0;
	virtual std::any visitNumberNode(NumberNode& numberNode) = 0;
	virtual std::any visitStringNode(StringNode& stringNode) = 0;
	virtual std::any visitIdentifierNode(IdentifierNode& identifierNode) = 0;
	virtual std::any visitUnaryNode(UnaryNode& unaryNode) = 0;

	virtual std::any visitExpressionStmt(ExpressionStmtNode& expressionStmtNode) = 0;
	virtual std::any visitPrintStmt(PrintStmtNode& printStmtNode) = 0;
	virtual std::any visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode) = 0;
	virtual std::any visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode) = 0;

	virtual std::any visitFunctionStmtNode(FunctionStmtNode& functionStmtNode) = 0;
	virtual std::any visitBlockStmtNode(BlockStmtNode& blockStmtNode) = 0;
};

