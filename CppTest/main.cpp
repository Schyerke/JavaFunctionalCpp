#include <iostream>
#include <cstring>
#include <string>
#include <memory>

#include <stdbool.h>

#include <stdio.h>

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
}


int main() {
	
	unique_ptr<Person> person = make_unique<Person>("Stefano", "Male");

	cout << person->name << endl;
	cout << person->surname;

	
	return 0;
}

