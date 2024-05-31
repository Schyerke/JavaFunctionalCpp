#include <vector>
#include <memory>
#include <list>
#include <iostream>

unsigned int Factorial(unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}



int main()
{
	std::unique_ptr<int> hello = std::make_unique<int>(52);
	std::unique_ptr<int>& lw = hello;

	std::cout << *lw;
}