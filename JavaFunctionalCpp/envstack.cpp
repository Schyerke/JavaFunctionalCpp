#include "envstack.hpp"

Enviroment EnvStack::get_env()
{
    return this->envs[this->current--];
}

void EnvStack::add_env(Enviroment env)
{
    this->envs[++this->last_index];
}

void EnvStack::reset()
{
    this->current = this->last_index;
}


