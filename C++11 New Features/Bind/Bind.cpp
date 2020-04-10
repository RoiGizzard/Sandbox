#include <iostream>
#include <functional>

class Test
{
public:
	int add(int a, int b, int c)
	{
		std::cout << a << ", " << b << ", " << c << std::endl;
		return a + b + c;
	}
};

int run(std::function<int(int, int)> func)
{
	return func(7, 3);
}

int main()
{
	Test t;
	auto calculator = std::bind(&Test::add, t, std::placeholders::_2, 100, std::placeholders::_1);

	std::cout << calculator(10, 20) << std::endl;

	std::cout << run(calculator) << std::endl;

	return 0;
}
