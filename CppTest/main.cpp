#include <vector>
#include <memory>
#include <list>

using namespace std;

struct A
{
    int a;
};

template<typename T>
struct B
{
    T t;
};

int main(int argc, char** argv)
{
    vector<B< vector<list<unique_ptr<A>>>>> v;
    v.emplace_back();
}