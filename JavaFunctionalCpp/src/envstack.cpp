#include "envstack.hpp"
#include "environment.hpp"

EnvStack::EnvStack()
{

}

std::optional<Environment> EnvStack::get()
{
    if (not this->envs.empty() || this->current >= 0)
    {
        return std::make_optional<Environment>(this->envs.at(current--));
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
    if (env.env_var.get(identifier) == std::nullopt)
    {
        return get(identifier);
    }
    reset();
    return { std::move(env.env_var.get(identifier).value()), env};
}

void EnvStack::push(Environment env)
{
    this->envs.push_back(env);
    this->last_index++;
    reset();
}

std::optional<Environment> EnvStack::pop()
{
    if (this->envs.empty())
    {
        return std::nullopt;
    }
    this->last_index--;
    reset();
    this->envs.pop_back();
}

void EnvStack::add(Variable var)
{
    Environment env = get().value();
    env.env_var.set(var);
    reset();
}

void EnvStack::assign(std::string identifier, std::any value)
{
    std::pair<Variable, Environment> var_op = get(identifier);
    var_op.second.env_var.assign(identifier, var_op.first);
}

void EnvStack::reset()
{
    this->current = this->last_index;
}


