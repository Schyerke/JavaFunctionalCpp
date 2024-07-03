#pragma once
#include <unordered_map>

#include "variable.hpp"


class FunctionMemory
{
public:
	void add(FuncVariable func_var);
	FuncVariable get(std::string identifier);
	bool exist(std::string identifier);
private:
	std::unordered_map<std::string, FuncVariable> func_vars;
};