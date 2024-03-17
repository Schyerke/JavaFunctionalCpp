#include "semantic.hpp"
#include "binaryexpression.hpp"
#include "boolnode.hpp"
#include "identifiernode.hpp"
#include "numbernode.hpp"
#include "stringnode.hpp"
#include "unarynode.hpp"
#include "expressionstmtnode.hpp"
#include "printstmtnode.hpp"
#include "varassignmentstmtnode.hpp"
#include "vardeclarationnode.hpp"

Semantic::Semantic(Enviroment env)
{
	this->env = env;
}

std::vector<std::string> Semantic::analyse(std::vector<std::unique_ptr<AstNode>> statements)
{
	for (auto& stmt : statements)
	{
		stmt->accept(*this);
	}
	return this->errors;
}

std::any Semantic::visitBinaryExpression(BinaryExpression& binaryExpression)
{
	std::any left = binaryExpression.left->accept(*this);
	std::any right = binaryExpression.right->accept(*this);
	Token_t op = binaryExpression.op;

	switch (op)
	{
		case PLUS_TOKEN:
			if (not (left.type() == typeid(short) && right.type() == typeid(short) ||
					 left.type() == typeid(int) && right.type() == typeid(int) ||
					 left.type() == typeid(long) && right.type() == typeid(long)))
			{
				add_err("Unmatched data type for number/string operation.");
			}
			break;
		case MINUS_TOKEN:
		case STAR_TOKEN:
		case SLASH_TOKEN:
			if (not (left.type() == typeid(short) && right.type() == typeid(short) ||
					 left.type() == typeid(int) && right.type() == typeid(int) ||
					 left.type() == typeid(long) && right.type() == typeid(long)))
			{
				add_err("Unmatched data type for number operation.");
			}
			break;

	}

	return std::any();
}

std::any Semantic::visitBoolNode(BoolNode& boolNode)
{
	bool v = boolNode.value;
	if (not (v == false || v == true)) 
	{
		add_err("Boolean value is invalid (must be either 'true' or 'false').");
	}
	return std::any();
}

std::any Semantic::visitNumberNode(NumberNode& numberNode)
{
	if (not isdigit(numberNode.number))
	{
		add_err("Number value is invalid.");
	}

	return std::any();
}

std::any Semantic::visitStringNode(StringNode& stringNode)
{
	return std::any();
}

std::any Semantic::visitIdentifierNode(IdentifierNode& identifierNode)
{
	try 
	{
		this->env.get(identifierNode.identifier)
	}
	catch (std::invalid_argument e)
	{
		add_err(e.what());
	}
	return std::any();
}

std::any Semantic::visitUnaryNode(UnaryNode& unaryNode)
{
	unaryNode.left->accept(*this);
	return std::any();
}

std::any Semantic::visitExpressionStmt(ExpressionStmtNode& expressionStmtNode)
{
	expressionStmtNode.expression->accept(*this);
	return std::any();
}

std::any Semantic::visitPrintStmt(PrintStmtNode& printStmtNode)
{
	printStmtNode.expression->accept(*this);
	return std::any();
}

std::any Semantic::visitVarDeclarationStmt(VarDeclarationNode& varDeclarationNode)
{
	Variable var;
	var.identifier = varDeclarationNode.identifier;
	var.dtType = tokent2datatype(varDeclarationNode.variableType);
	varDeclarationNode.expression->accept(*this);
	try
	{
		this->env.set(var);
	}
	catch (std::invalid_argument e)
	{
		add_err(e.what());
	}
	return std::any();
}

std::any Semantic::visitVarAssignmentStmt(VarAssignmentStmtNode& varAssignmentNode)
{
	varAssignmentNode.expression->accept(*this);
	try
	{
		this->env.get(varAssignmentNode.identifier);
		// check value and var data type
	}
	catch (std::invalid_argument e)
	{
		add_err(e.what());
	}
	return std::any();
}

void Semantic::add_err(std::string error)
{
	this->errors.push_back(error);
}
