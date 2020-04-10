#include <iostream>

int main()
{
	int cats = 5;

	[cats]() mutable {
		cats = 8;
		std::cout << cats << std::endl;
	}();

	std::cout << cats << std::endl;
}
