#include <iostream>
#include <cstring>
#include <string>
#include <memory>

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
	Dog* dog = new Dog();
	
	unique_ptr<Dog> u = make_unique<Dog>(*dog);
	cout << u.get()->name;
	

	return 0;
}

