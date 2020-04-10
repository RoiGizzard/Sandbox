#include <iostream>

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;

	// Capture one and two by value
	[one, two]() {std::cout << one << "," << two << std::endl; }();

	// Capture all local variable by value
	[=]() {std::cout << one << "," << two << std::endl; }();

	// Capture all local variable by value, but capture three bu reference
	[=, &three]() { 
		three = 7;
		std::cout << one << "," << two << std::endl; 
	}();
	std::cout << three << std::endl;

	// Capture all local variable by reference
	[&]() { std::cout << one << "," << two << std::endl; }();

	// Capture all local variable by reference, but two and three by value
	[&, two, three]() { 
		one = 100;
		std::cout << one << "," << two << std::endl; 
	}();
	std::cout << one << std::endl;
}
