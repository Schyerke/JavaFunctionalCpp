#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <any>
#include <variant>

using namespace std;

struct Person
{
	int age;
	string name = "he";
};

int f2()
{
	return {};
}

int main() {
	int w = f2();

	cout << w;

	return 0;
}

