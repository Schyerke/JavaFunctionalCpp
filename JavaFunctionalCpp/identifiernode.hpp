#ifndef IDENTIFIER_NODE_HPP
#define IDENTIFIER_NODE_HPP

#include "astnode.hpp"

class IdentifierNode : public AstNode {
public:
	std::string identifier;
	IdentifierNode(std::string identifier);

	std::string get_classname();
};


#endif // !IDENTIFIER_NODE_HPP
