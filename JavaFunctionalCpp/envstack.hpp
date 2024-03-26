#pragma once

#include <optional>
#include <vector>

class Environment;

class EnvStack
{
public:
	std::vector<Environment> envs;
	int last_index = 0;
	int current = last_index;

	std::optional<Environment> get_env();
	void add_env(Environment env);
	void reset();
};