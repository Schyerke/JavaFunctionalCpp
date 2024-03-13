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

};


void f1(Person& person)
{
	Person& p1 = person;
	p1.name = "f1";
}

void f2(Person& person)
{
	Person& p2 = person;
	p2.name = "f2";
}

int main() {
	Person person;
	person.name = "First";

	cout << person.name << endl;
	f1(person);
	cout << person.name << endl;
	f2(person);
	cout << person.name << endl;


	return 0;
}

