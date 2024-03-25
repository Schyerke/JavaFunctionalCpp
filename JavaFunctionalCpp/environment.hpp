#pragma once

#include <iostream>
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

	class Func_Var
	{
		
	};

	Var var;

};

