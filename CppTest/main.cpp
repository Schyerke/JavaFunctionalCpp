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
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			for (int k = 0; k < 1000; k++)
			{
				if (i == 500)
				{
					cout << "wtf" << endl;
					goto l;
				}
			}
		}
	}
l:	
	cout << "Finisehd";

	return 0;
}

