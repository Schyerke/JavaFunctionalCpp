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

std::vector<std::string> Semantic::analyse(std::vector<std::unique_ptr<AstNode>>& statements)
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
		case MINUS_TOKEN:
		case STAR_TOKEN:
		case SLASH_TOKEN:
			if (left.type() == typeid(short) && right.type() == typeid(short))
			{
				return (short)1;
			}
			if (left.type() == typeid(int) && right.type() == typeid(int))
			{
				return (int)1;
			}
			if (left.type() == typeid(long) && right.type() == typeid(long))
			{
				return (long)1;
			}
			if (left.type() == typeid(float) && right.type() == typeid(float))
			{
				return (float)1;
			}
			if (left.type() == typeid(double) && right.type() == typeid(double))
			{
				return (double)1;
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
	return (bool)true;
}

std::any Semantic::visitNumberNode(NumberNode& numberNode)
{
	NUMBER_DT nn = numberNode.number;
	if (std::holds_alternative<short>(nn))
	{
		return (short)1;
	}
	if (std::holds_alternative<int>(nn))
	{
		return (int)1;
	}
	if (std::holds_alternative<long>(nn))
	{
		return (long)1;
	}
	if (std::holds_alternative<float>(nn))
	{
		return (float)1;
	}
	if (std::holds_alternative<double>(nn))
	{
		return (double)1;
	}

	add_err("Number value is invalid.");
	return std::any();
}

std::any Semantic::visitStringNode(StringNode& stringNode)
{
	return stringNode.value;
}

std::any Semantic::visitIdentifierNode(IdentifierNode& identifierNode)
{
	try 
	{
		Variable v = std::move(this->env.var.get(identifierNode.identifier));
		return v.value;
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
	var.dtType = from_TokenT_to_DataType(varDeclarationNode.variableType);
	var.value = varDeclarationNode.expression->accept(*this);
	try
	{
		this->env.var.set(var);
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
		return this->env.var.get(varAssignmentNode.identifier).dtType;
	}
	catch (std::invalid_argument e)
	{
		add_err(e.what());
	}
	return std::any();
}

std::any Semantic::visitFunctionStmtNode(FunctionStmtNode& functionStmtNode)
{
	return std::any();
}

std::any Semantic::visitBlockStmtNode(BlockStmtNode& blockStmtNode)
{
	return std::any();
}

void Semantic::add_err(std::string error)
{
	this->errors.push_back(error);
}
