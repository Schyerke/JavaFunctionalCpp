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

void f5(int s)
{
	cout << s;
}

int main() {
	std::variant<int, std::string> w = 3;
	std::get<int>(w);


	
	
	return 0;
}

