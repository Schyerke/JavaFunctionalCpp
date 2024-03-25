#include "environment.hpp"

Enviroment::Enviroment()
{
}

Variable Enviroment::Var::get(std::string identifier)
{
    if (this->variables.contains(identifier))
    {
        return this->variables[identifier];
    }
    throw std::invalid_argument("Identifier '" + identifier + "' not found.");
}

void Enviroment::Var::set(Variable variable)
{
    if (this->variables.contains(variable.identifier))
    {
        throw std::invalid_argument("Identifier '" + variable.identifier + "' already declared.");
    }
    this->variables[variable.identifier] = variable;
}

void Enviroment::Var::assign(std::string identifier, std::any value)
{
    if (not this->variables.contains(identifier))
    {
        throw std::invalid_argument("Identifier '" + identifier + "' not found.");
    }
    Variable var = this->variables[identifier];
    var.value = value;
    this->variables[identifier] = var;
}

FuncVariable Enviroment::FuncVar::get(std::string identifier)
{
    if (this->func_variables.contains(identifier))
    {
        return std::move(this->func_variables[identifier]);
    }
    throw std::invalid_argument("Function Identifier '" + identifier + "' not found.");
}

void Enviroment::FuncVar::set(FuncVariable func_var)
{
    if (this->func_variables.contains(func_var.identifier))
    {
        throw std::invalid_argument("Function Identifier '" + func_var.identifier + "' already declared.");
    }
    this->func_variables.emplace(func_var.identifier, std::move(func_var));
}
