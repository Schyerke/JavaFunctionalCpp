#ifndef PRINT_STMT_NODE_HPP
#define PRINT_STMT_NODE_HPP

#include "astnode.hpp"

class PrintStmtNode : public AstNode
{
public:
	AstNode* expression;

	PrintStmtNode(AstNode* expression);
};



#endif // !PRINT_STMT_NODE_HPP
