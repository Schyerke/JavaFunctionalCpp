#ifndef EXPRESSION_STMT_NODE_HPP
#define EXPRESSION_STMT_NODE_HPP

#include "astnode.hpp"

class ExpressionStmtNode : public AstNode
{
public:
	std::unique_ptr<AstNode> expression;

	ExpressionStmtNode(std::unique_ptr<AstNode> expression);
};


#endif // !EXPRESSION_STMT_NODE_HPP
