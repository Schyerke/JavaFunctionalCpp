#include "semantic.hpp"
#include "binaryexpression.hpp"

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
}

void Semantic::add_err(std::string error)
{
	this->errors.push_back(error);
}
