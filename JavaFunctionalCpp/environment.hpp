#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "vardeclarationnode.hpp"

class Enviroment {
public:
	Enviroment();

	class Var
	{
	public:
		Variable get(std::string identifier);
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
