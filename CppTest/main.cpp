#include <vector>
#include <memory>
#include <list>
#include <iostream>

#include <catch.hpp>
#include <catch2/catch_test_macros.hpp>


unsigned int Factorial(unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 3);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}


int main()
{
	std::unique_ptr<int> hello = std::make_unique<int>(52);
	std::unique_ptr<int>& lw = hello;

	std::cout << *lw;
}