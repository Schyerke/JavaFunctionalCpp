#ifndef INTERPRET_HPP
#define INTERPRET_HPP

#include <iostream>
#include <any>
#include "visitor.hpp"

class Interpreter : public Visitor {
	void interpret();
	std::any visitNumberNode(NumberNode& numberNode);
	std::any visitUnaryNode(UnaryNode& unaryNode);
	std::any visitBinaryExpression(BinaryExpression& binaryExpression);
};



#endif // !INTERPRET_HPP
