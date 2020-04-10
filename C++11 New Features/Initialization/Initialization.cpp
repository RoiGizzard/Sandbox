#include <iostream>
#include <vector>

int main()
{
	// C++98
	int values[] = { 1, 2, 3 };
	std::cout << values[0] << std::endl;

	class C {
	public:
		std::string text;
		int id;
	};

	C c1 = { "Hello", 7 };
	std::cout << c1.text << std::endl;

	struct S {
		std::string text;
		int id;
	};
	S s1 = { "Hello", 7 };
	std::cout << s1.text << std::endl;

	struct {
		std::string text;
		int id;
	} r1 = { "Hello", 8 }, r2 = {"Hi", 9};
	std::cout << r1.text << " " << r2.text << std::endl;

	// C++11
	int value{5};
	std::cout << value << std::endl;

	std::string text{ "Bob" };
	std::cout << text << std::endl;

	int numbers[]{ 1, 2, 3 };
	std::cout << numbers[1] << std::endl;

	int* pInts = new int[3]{ 4, 5, 6 };
	std::cout << pInts[1] << std::endl;

	int* pSomething{}; // Equivalent to int *pSomething = nullptr;
	
	int numbers2[5]{};
	std::cout << numbers2[1] << std::endl;

	struct {
		int value;
		std::string text;
	} s2 { 4, "joe" };

	std::vector<int> v{ 1, 2, 3, 4, 5 };
	std::cout << v[4] << std::endl;
}
