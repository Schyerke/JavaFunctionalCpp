#ifndef IDENTIFIER_NODE_HPP
#define IDENTIFIER_NODE_HPP

#include "astnode.hpp"
#include "token.hpp"


class VarDeclarationNode : public AstNode {
public:
	Token_t variableType;
	std::string identifier;
	VarDeclarationNode(Token_t variableType, std::string identifier);

	std::string get_classname();
};


#endif // !IDENTIFIER_NODE_HPP
