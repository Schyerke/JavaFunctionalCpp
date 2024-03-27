#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <any>
#include <variant>

#include <unordered_map>
#include <stack>

using namespace std;

class Cat {
	std::unique_ptr<std::string> w;
};

class Person
{
	std::unique_ptr<int> age;
	std::unordered_map<int, Cat> lll;
};
int main() {

	Person person;
	
	std::vector<Person> vec;
	vec.push_back(std::move(person));
	return 0;
}

