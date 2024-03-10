#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <any>
#include <variant>



using namespace std;

class Person
{
public:
	string name;
	string surname;

	Person(Person& p);
	Person(string name, string surname);
};

Person::Person(string name, string surname)
{
	this->name = name;
	this->surname = surname;
};

Person::Person(Person& p)
{
	cout << "I'm being called";
}

template<typename T>
T evaluate(T left, T right)
{
	return left + right;
}

std::any w()
{
	std::string s = "hello";
	return s;
}

int main() {
	cout << w().type().name();

	if (w().type() == typeid(std::string))
		cout << "Vero";

	return 0;
}

