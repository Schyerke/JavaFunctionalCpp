#ifndef PRINT_STMT_NODE_HPP
#define PRINT_STMT_NODE_HPP

#include "astnode.hpp"

class PrintStmtNode : public AstNode
{
public:
	std::unique_ptr<AstNode> expression;

	PrintStmtNode(std::unique_ptr<AstNode> expression);
	std::any accept(Visitor& visitor);
};



#endif // !PRINT_STMT_NODE_HPP
