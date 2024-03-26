#pragma once

#include <vector>

#include "astnode.hpp"
#include "environment.hpp"

class BlockStmtNode : public AstNode
{
public:
	BlockStmtNode(std::vector<std::unique_ptr<AstNode>>& stmts);
	std::any accept(Visitor& visitor);

	Environment block_env;
	std::vector<std::unique_ptr<AstNode>>& stmts;
};

