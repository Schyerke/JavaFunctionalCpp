#include <vector>
#include <memory>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	std::unique_ptr<int> hello = std::make_unique<int>(52);
	std::unique_ptr<int>& lw = hello;

	std::cout << *lw;
}