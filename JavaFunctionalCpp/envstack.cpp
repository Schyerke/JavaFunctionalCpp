#include "envstack.hpp"
#include "environment.hpp"

EnvStack::EnvStack()
{

}

std::optional<Environment> EnvStack::get()
{
    if (this->current >= 0 && not this->envs.size() == 0)
    {
        return std::make_optional<Environment>(std::move(this->envs.at(current--)));
    }
    return std::nullopt;
}

std::pair<Variable, Environment> EnvStack::get(std::string identifier)
{
    std::optional<Environment> env_op = std::move(get());
    if (env_op == std::nullopt)
    {
        throw std::invalid_argument("Variable Identifier '" + identifier + "' not found.");
    }
    Environment env = std::move(env_op.value());
    if (env.var.get(identifier) == std::nullopt)
    {
        return std::move(get(identifier));
    }
    reset();
    return { std::move(env.var.get(identifier).value()), std::move(env)};
}

void EnvStack::add(Environment env)
{
    //this->envs[++this->last_index] = std::move(env);
    //this->envs.push_back(std::move(env));
    reset();
}

void EnvStack::add(Variable var)
{
    Environment env = std::move(get().value());
    env.var.set(var);
    reset();
}

void EnvStack::assign(std::string identifier, std::any value)
{
    std::pair<Variable, Environment> var_op = std::move(get(identifier));
    var_op.second.var.assign(identifier, std::move(var_op.first));
}

void EnvStack::reset()
{
    this->current = this->last_index;
}


