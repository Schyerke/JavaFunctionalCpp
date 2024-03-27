#include <unordered_map>
#include <any>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <utility>
#include <stdexcept>

struct Variable
{
    int dtType;
    std::string identifier;
    std::any value;

};

struct FuncVariable
{
    int return_type;
    std::string identifier;
    std::unique_ptr<int> block_stmt;
};

class Environment {
public:
    std::string identifier; // could be function name, or null (general blockstmt)
    Environment() {}

    class Var
    {
    public:
        std::optional<Variable> get(std::string identifier) {
            return std::nullopt;
        }
        void set(Variable variable) {}
        void assign(std::string identifier, std::any value) {}
    private:
        std::unordered_map<std::string, Variable> variables;
    };

    class FuncVar
    {
    public:
        FuncVariable get(std::string identifier) {
            return {};
        }
        void set(FuncVariable func_var) {}
    private:
        std::unordered_map<std::string, FuncVariable> func_variables;
    };

    Var var;
    FuncVar func_var;
};

class EnvStack
{
public:
    EnvStack();

    std::vector<Environment> envs;
    int last_index = 0;
    int current = last_index;

    std::optional<Environment> get();
    std::pair<Variable, Environment> get(std::string identifier);
    void add(Environment env);
    void add(Variable var);
    void assign(std::string identifier, std::any value);
    void reset();
};

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
    return { std::move(env.var.get(identifier).value()), std::move(env) };
}

void EnvStack::add(Environment env)
{
    //this->envs[++this->last_index] = std::move(env);
    this->envs.emplace_back(std::move(env));
    reset();
}

void EnvStack::add(Variable var)
{
    Environment env = std::move(get().value());
    env.var.set(std::move(var));
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

int main()
{
    EnvStack s;
    Environment w;
    s.add(std::move(w));
}