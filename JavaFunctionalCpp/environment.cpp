#include "environment.hpp"

Enviroment::Enviroment()
{
}

Variable Enviroment::get(std::string identifier)
{
    if (this->variables.contains(identifier))
    {
        return std::move(this->variables[identifier]);
    }
    throw std::invalid_argument("Identifier '" + identifier + "' not found.");
}

void Enviroment::set(Variable variable)
{
    if (this->variables.contains(variable.identifier))
    {
        throw std::invalid_argument("Identifier '" + variable.identifier + "' already declared.");
    }
    this->variables[variable.identifier] = std::move(variable);
}

void Enviroment::assign(std::string identifier, std::any value)
{
    if (!this->variables.contains(identifier))
    {
        throw std::invalid_argument("Identifier '" + identifier + "' not found.");
    }
    Variable var = std::move(this->variables[identifier]);
    var.value = value;
    this->variables[identifier] = std::move(var);
}
