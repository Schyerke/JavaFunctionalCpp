#include <vector>
#include <memory>
#include <list>
#include <iostream>

using namespace std;

class A
{
public:
	std::unique_ptr< int > up_;
	A(int i) : up_(new int(i)) {}
	A(const A& a) : up_(new int(*a.up_)) {}
};

int main()
{
	A a(42);
	A b = a;

	cout << *a.up_;
	cout << endl << *b.up_;
}