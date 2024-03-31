#pragma once

#include <optional>
#include <vector>
#include <iostream>

#include "variable.hpp"

class Environment;

class EnvStack
{
public:
	EnvStack();

	std::vector<Environment> envs;
	int last_index = 0;
	int current = last_index;

	std::optional<Environment> get();
	std::pair<Variable, Environment> get(std::string identifier);
	void push(Environment env);
	std::optional<Environment> pop();
	void add(Variable var);
	void assign(std::string identifier, std::any value);
	void reset();
};
