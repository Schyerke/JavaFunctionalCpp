#include "astnode.hpp"
#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

enum ResultType {
    BOOLEAN,
    NUMBER,
    STRING,
    IDENTIFER,

    NO_RESULT
};

struct Result {
    ResultType resultType;
    long number;
    std::string str;
    std::string identifier;
    bool boolean;
};


class Evaluator
{
public:
	Evaluator();
	Result evaluate(AstNode* node);
};



#endif // !EVALUATOR_HPP
