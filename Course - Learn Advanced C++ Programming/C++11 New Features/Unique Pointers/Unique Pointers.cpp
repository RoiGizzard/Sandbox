#include <iostream>
#include <memory>

class Test
{
public:
	Test()
	{
		std::cout << "Created" << std::endl;
	}

	void greet()
	{
		std::cout << "Hello" << std::endl;
	}

	~Test()
	{
		std::cout << "Destroyed" << std::endl;
	}
};

class Temp
{
public:
	Temp()
		: pTest(new Test[2])
	{}

private:
	std::unique_ptr<Test[]> pTest;
};

int main()
{
	//std::unique_ptr<Test[]> pTest(new Test[2]);
	//pTest[1].greet();

	Temp temp; // no need for destructor to clean memory

	std::cout << "Finished" << std::endl;

	return 0;
}

