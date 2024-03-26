#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <optional>
#include <vector>

#include "vardeclarationnode.hpp"

class Environment {
public:
	std::string identifier; // could be function name, or null (general blockstmt)
	Environment();

	class Var
	{
	public:
		std::optional<Variable> get(std::string identifier);
		void set(Variable variable);
		void assign(std::string identifier, std::any value);
	private:
		std::unordered_map<std::string, Variable> variables;
	};

	class FuncVar
	{
	public:
		FuncVariable get(std::string identifier);
		void set(FuncVariable func_var);
	private:
		std::unordered_map<std::string, FuncVariable> func_variables;
	};

	Var var;
	FuncVar func_var;
};
