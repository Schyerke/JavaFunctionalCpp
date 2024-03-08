#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <any>
#include <iostream>

#include "numbernode.hpp"
#include "unarynode.hpp"
#include "binaryexpression.hpp"

class Visitor {
public:
	virtual std::any visitNumberNode(NumberNode numberNode) = 0;
	virtual std::any visitUnaryNode(UnaryNode unaryNode) = 0;
	virtual std::any vistiBinaryExpression(BinaryExpression binaryExpression) = 0;
};

#endif // !VISITOR_HPP
