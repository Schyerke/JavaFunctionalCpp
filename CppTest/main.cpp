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
	
	std::variant<int, long, double> variable = 4;
	std::variant<int, long, double> lll = 2;

	auto o = std::visit([]<class T, class Y>(T var1, Y var2) -> std::variant<int, long, double>
	{
		auto result = (T)var1 + (Y)var2;
		return result;
	}, variable, lll);


	if (std::holds_alternative<int>(o))
	{
		std::cout << std::get<int>(o) << " int";
	}
	if (std::holds_alternative<long>(o))
	{
		std::cout << std::get<long>(o) << " long";
	}
	if (std::holds_alternative<double>(o))
	{
		std::cout << std::get<double>(o) << " double";
	}

	return 0;
}

