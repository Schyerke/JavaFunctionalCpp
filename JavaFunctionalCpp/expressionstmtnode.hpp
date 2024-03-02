#ifndef EXPRESSION_STMT_NODE_HPP
#define EXPRESSION_STMT_NODE_HPP

#include "astnode.hpp"

class ExpressionStmtNode : public AstNode
{
public:
	AstNode* expression;

	ExpressionStmtNode(AstNode* expression);
};


#endif // !EXPRESSION_STMT_NODE_HPP
