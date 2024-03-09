#ifndef BOOL_NODE_HPP
#define BOOL_NODE_HPP

#include "astnode.hpp"

class BoolNode : public AstNode {
public:
	bool value;
	BoolNode(bool value);
	std::string get_classname();
	std::any accept(Visitor& visitor);
};

#endif // !BOOL_NODE_HPP
