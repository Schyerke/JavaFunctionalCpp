#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <any>
#include <variant>

using namespace std;


struct Person {
	std::unique_ptr<int> age;
};

void f1(Person person)
{
	cout << *person.age << endl;
}

int main() {
	
	Person person;
	person.age = std::make_unique<int>(42);

	f1(std::move(person));


	return 0;
}

