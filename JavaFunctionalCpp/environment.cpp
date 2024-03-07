#include "environment.hpp"

Enviroment::Enviroment()
{
}

Variable Enviroment::get(std::string identifier)
{
    Variable var = this->variables[identifier];
    return var;
}

void Enviroment::set(Variable variable)
{
    this->variables[variable.identifier] = variable;
}
