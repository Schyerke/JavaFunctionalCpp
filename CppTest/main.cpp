#include <iostream>
#include <cstring>
#include <string>
#include <memory>

#include <stdbool.h>

#include <stdio.h>

using namespace std;



class Animal {
public:
	string name;
	Animal() {
		name = "Animal";
	}
	virtual void eat() {
		cout << "General animal eating";
	}
};

class Dog : public Animal{
public:
	Dog() {
		name = "Dog";
	}
	void eat() override {
		cout << "Dog is eating";
	}
};


int main() {
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Tu invece?" << std::endl;
	}

	return 0;
}

