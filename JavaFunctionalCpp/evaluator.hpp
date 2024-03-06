#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include "astnode.hpp"
#include "environment.hpp"

enum ResultType {
    RT_BOOLEAN,
    RT_NUMBER,
    RT_STRING,
    RT_VARIABLE,

    RT_NO_RESULT
};

struct Result {
    ResultType resultType;
    long number;
    std::string str;
    Variable variable;
    bool boolean;
};


class Evaluator
{
public:
	Evaluator(Enviroment env);
	Result evaluate(AstNode* node);
    Enviroment get_env();
private:
    Enviroment env;
};



#endif // !EVALUATOR_HPP
