#include "envstack.hpp"
#include "environment.hpp"

EnvStack::EnvStack()
{

}

std::optional<Environment> EnvStack::get_env()
{
    if (this->current >= 0)
    {
        return std::make_optional<Environment>(std::move(this->envs[current--]));
    }
    return std::nullopt;
}

void EnvStack::add_env(Environment env)
{
    this->envs[++this->last_index] = std::move(env);
}

void EnvStack::reset()
{
    this->current = this->last_index;
}


