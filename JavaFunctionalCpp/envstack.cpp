#include "envstack.hpp"
#include "environment.hpp"

EnvStack::EnvStack()
{
}

std::optional<Environment> EnvStack::get()
{
    if (not this->envs.empty() && this->current >= 0)
    {
        return std::make_optional<Environment>(this->envs.at(current--));
    }
    return std::nullopt;
}

Environment& EnvStack::get_ref()
{
    if (not this->envs.empty() && this->current >= 0)
    {
        return this->envs.at(current--);
    }
    throw new std::invalid_argument("No Environment Found.");
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
    return { env.env_var.get(identifier).value(), env};
}

void EnvStack::push(Environment env)
{
    this->envs.push_back(std::move(env));
    this->last_index++;
    reset();
}

std::optional<Environment> EnvStack::pop()
{
    if (this->envs.empty())
    {
        return std::nullopt;
    }
    Environment deleted_env = this->envs.at(last_index);
    this->last_index--;
    this->envs.pop_back();
    reset();
    return std::make_optional<Environment>(deleted_env);
}

void EnvStack::add(Variable var)
{
    try
    {
        Environment& env = get_ref();
        env.env_var.set(var);
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
    }

     reset();
}

void EnvStack::assign(std::string identifier, std::any value)
{
    std::pair<Variable, Environment> var_op = std::move(get(identifier));
    var_op.second.env_var.assign(identifier, std::move(var_op.first));
}

void EnvStack::reset()
{
    this->current = this->last_index;
}


