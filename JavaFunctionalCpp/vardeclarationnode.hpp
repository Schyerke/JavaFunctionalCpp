#ifndef IDENTIFIER_NODE_HPP
#define IDENTIFIER_NODE_HPP

#include "astnode.hpp"
#include "token.hpp"
#include "variable.hpp"

class VarDeclarationNode : public AstNode {
public:
	Token_t variableType;
	std::string identifier;
	std::string value = "";
	VarDeclarationNode(Token_t variableType, std::string identifier);
	VarDeclarationNode(Token_t variableType, std::string identifier, std::string value);

	std::any accept(Visitor& visitor);

};


#endif // !IDENTIFIER_NODE_HPP
