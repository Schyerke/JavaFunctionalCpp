#include <iostream>

#include "astnode.hpp"
#include "binaryexpression.hpp"
#include "numbernode.hpp"
#include "unarynode.hpp"

std::string get_node_classname(AstNode* node) {
	if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node)) {
		return numberNode->get_classname();
	}
	if (BinaryExpression* binary = dynamic_cast<BinaryExpression*>(node)) {
		return binary->get_classname();
	}
	if (UnaryNode* unaryNode = dynamic_cast<UnaryNode*>(node)) {
		return unaryNode->get_classname();
	}
	return "";
}