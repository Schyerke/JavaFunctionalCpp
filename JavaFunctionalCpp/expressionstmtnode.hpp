#ifndef EXPRESSION_STMT_NODE_HPP
#define EXPRESSION_STMT_NODE_HPP

#include "astnode.hpp"

class ExpressionStmtNode : public AstNode
{
public:
	std::unique_ptr<AstNode> expression;

	ExpressionStmtNode(std::unique_ptr<AstNode> expression);
	std::any accept(Visitor& visitor);
};


#endif // !EXPRESSION_STMT_NODE_HPP
