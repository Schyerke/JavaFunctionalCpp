#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <optional>
#include <vector>

#include "vardeclarationnode.hpp"

class Environment {
public:
	Environment(Environment&& env) = default;
	Environment(Environment& env) = delete;

	std::string identifier; // could be function name, or null (general blockstmt)
	Environment();

	class EnvVar
	{
	public:
		std::optional<Variable> get(std::string identifier);
		void set(Variable variable);
		void assign(std::string identifier, std::any value);
	private:
		std::unordered_map<std::string, Variable> variables;
	};

	EnvVar env_var;
};
