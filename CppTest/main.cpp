#include <vector>
#include <memory>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	std::unique_ptr<int> s = {};
	cout << s;
	if (s == nullptr)
	{
		cout << "si";
	}
}