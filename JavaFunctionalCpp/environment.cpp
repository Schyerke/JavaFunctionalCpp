#include "environment.hpp"


Environment::Environment()
{
}

std::optional<Variable> Environment::EnvrionmentVariable::get(std::string identifier)
{
    if (this->variables.contains(identifier))
    {
        return this->variables[identifier];
    }
    return std::nullopt;
}

void Environment::EnvrionmentVariable::set(Variable variable)
{
    if (this->variables.contains(variable.identifier))
    {
        throw std::invalid_argument("Identifier '" + variable.identifier + "' already declared.");
    }
    this->variables[variable.identifier] = variable;
}

void Environment::EnvrionmentVariable::assign(std::string identifier, std::any value)
{
    if (not this->variables.contains(identifier))
    {
        throw std::invalid_argument("Identifier '" + identifier + "' not found.");
    }
    Variable var = this->variables[identifier];
    var.value = value;
    this->variables[identifier] = var;
}
