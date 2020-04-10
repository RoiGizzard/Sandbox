#include <iostream>

void testGreet(void(*greet)(int))
{
	greet(2);
}

void testDivide(double (*divide)(double, double))
{
	auto rval = divide(12, 3);
	std::cout << rval << std::endl;
}

int main()
{
	auto pGreet = [](int v) { std::cout << v << std::endl; };
	pGreet(1);

	testGreet(pGreet);

	auto pDivide = [](double a, double b) -> double { 
		if (b == 0.0)
		{
			return 0;
		}

		return a / b; 
	};

	std::cout << pDivide(15.0, 5.0) << std::endl;
	std::cout << pDivide(15.0, 0.0) << std::endl;

	testDivide(pDivide);
}
