#include <iostream>
#include <vector>


class Test
{
public:
	Test()
	{
		std::cout << "Constructor" << std::endl;
	}

	Test(int)
	{
		std::cout << "Parametized constructor" << std::endl;
	}

	Test(const Test &)
	{
		std::cout << "Copy constructor" << std::endl;
	}

	Test &operator = (const Test &)
	{
		std::cout << "Assignment" << std::endl;
		return *this;
	}

	~Test()
	{
		std::cout << "Destructor" << std::endl;
	}

	friend std::ostream &operator<<(std::ostream &out, const Test &test);
};

std::ostream &operator<<(std::ostream &out, const Test & test)
{
	out << "Hello from test";
	return out;
}

Test getTest()
{
	return Test();
}

int main()
{
	// -fno-elide-constructors to see the mess
	Test test1 = getTest();

	std::cout << test1 << std::endl;

	std::vector<Test> vec;
	vec.push_back(Test());

	return 0;
}
