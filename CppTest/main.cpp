#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <any>



using namespace std;

class Person
{
public:
	string name;
	string surname;

	Person(string name, string surname);
};

Person::Person(string name, string surname)
{
	this->name = name;
	this->surname = surname;
};

std::any visit(std::any a) {
	return "hello";
}

int main() {
	std::any s = visit(2);
	
	const char* w = std::any_cast<const char*>(s);

	cout << w;
	
	return 0;
}

