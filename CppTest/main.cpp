#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <any>
#include <variant>

#include <unordered_map>

using namespace std;

struct Person
{
	Person()
	{

	}
	unique_ptr<int> age;
	string name = "he";
};


unordered_map<int, Person> w;


void F1(Person person)
{
	cout << person.name << endl;
}

void F2(Person person)
{
	w[2] = std::move(person);
}

int main() {
	
	
	
	F2(std::move(Person()));
	cout << w[2].name << endl;



	return 0;
}

