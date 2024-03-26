#include "envstack.hpp"
#include "environment.hpp"

EnvStack::EnvStack()
{

}

std::optional<Environment> EnvStack::get()
{
    if (this->current >= 0)
    {
        return std::make_optional<Environment>(std::move(this->envs[current--]));
    }
    return std::nullopt;
}

std::pair<Variable, Environment> EnvStack::get(std::string identifier)
{
    std::optional<Environment> env_op = get();
    if (env_op == std::nullopt)
    {
        throw std::invalid_argument("Variable Identifier '" + identifier + "' not found.");
    }
    Environment env = env_op.value();
    if (env.var.get(identifier) == std::nullopt)
    {
        return { get(identifier), env };
    }
    reset();
    return { env.var.get(identifier).value(), env };
}

void EnvStack::add(Environment env)
{
    this->envs[++this->last_index] = std::move(env);
    reset();
}

void EnvStack::add(Variable var)
{
    Environment env = get().value();
    env.var.set(var);
    reset();
}

void EnvStack::assign(std::string identifier, std::any value)
{
    Variable var_op = get(identifier);
    var_op.value = value;

}

void EnvStack::reset()
{
    this->current = this->last_index;
}


