#pragma once

#include <iostream>
#include <unordered_map>

#include "vardeclarationnode.hpp"

class Enviroment {
public:
	Enviroment();

	Variable get(std::string identifier);
	void set(Variable variable);

private:
	std::unordered_map<std::string, Variable> variables;
};

