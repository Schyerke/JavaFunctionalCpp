#include "envstack.hpp"
#include "environment.hpp"

EnvStack::EnvStack()
{
}

std::optional<Environment> EnvStack::get_env()
{
    if (this->current >= 0)
    {
        return this->envs[current--];
    }
    return std::nullopt;
}

void EnvStack::add_env(Environment env)
{
    this->envs[++this->last_index] = env;
}

void EnvStack::reset()
{
    this->current = this->last_index;
}


