#include <iostream>

#include "astnode.hpp"
#include "binaryoperationnode.hpp"
#include "numbernode.hpp"

std::string get_node_classname(AstNode* node) {
	if (NumberNode* numberNode = dynamic_cast<NumberNode*>(node)) {
		return numberNode->get_classname();
	}
	if (BinaryOperationNode* binary = dynamic_cast<BinaryOperationNode*>(node)) {
		return binary->get_classname();
	}
	return "";
}