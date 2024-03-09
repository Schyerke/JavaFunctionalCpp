#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <any>
#include <iostream>

#include "numbernode.hpp"
#include "unarynode.hpp"
#include "binaryexpression.hpp"
#include "stringnode.hpp"
#include "boolnode.hpp"

class Visitor {
public:
	virtual std::any visitBinaryExpression(BinaryExpression& binaryExpression) = 0;
	virtual std::any visitBoolNode(BoolNode& boolNode) = 0;
	virtual std::any visitNumberNode(NumberNode& numberNode) = 0;
	virtual std::any visitStringNode(StringNode& stringNode) = 0;
	virtual std::any visitUnaryNode(UnaryNode& unaryNode) = 0;
};

#endif // !VISITOR_HPP
