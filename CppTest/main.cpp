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
	long s = 2;

	std::variant<int, long> w = s;

	int m = w;


	return 0;
}

