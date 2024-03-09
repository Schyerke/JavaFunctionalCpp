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

int main() {
	
	bool s = true;
	cout << s;



	return 0;
}

