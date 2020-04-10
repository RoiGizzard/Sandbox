#include <iostream>

class Test
{

};

template<typename T>
void call(T &&arg)
{
	check(std::forward<T>(arg));
}

void check(Test &)
{
	std::cout << "lValue" << std::endl;
}

void check(Test &&)
{
	std::cout << "rValue" << std::endl;
}

int main()
{
	Test test;

	call(test); // No perfect forwarding
	call(Test());

	return 0;
}
