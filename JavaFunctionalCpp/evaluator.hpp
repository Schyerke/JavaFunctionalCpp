#include "astnode.hpp"
#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP



class Evaluator
{
public:
	Evaluator();
	long evaluate(AstNode* node);
};



#endif // !EVALUATOR_HPP
