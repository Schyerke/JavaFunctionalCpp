#include <vector>
#include <memory>
#include <list>
#include <iostream>

using namespace std;

class Person {
public:

	Person()
	{

	}

	Person(Person&& p)
	{

	};
	Person(Person& p) = delete;

	int age = 0;
};

int main(int argc, char** argv)
{
	Person person;
	person.age = 52;
	Person p1 = std::move(person);
}