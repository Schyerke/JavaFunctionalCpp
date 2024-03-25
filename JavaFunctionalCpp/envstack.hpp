#pragma once

#include "environment.hpp"

class EnvStack
{
public:
	std::vector<Enviroment> envs;
	int last_index = 0;
	int current = last_index;

	Enviroment get_env();
	void add_env(Enviroment env);
	void reset();
};