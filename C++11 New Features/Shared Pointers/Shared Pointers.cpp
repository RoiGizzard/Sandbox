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

int main()
{
	std::shared_ptr<Test> pTest2(nullptr);
	
	{
		std::shared_ptr<Test> pTest = std::make_shared<Test>();
		pTest2 = pTest;
		auto pTest3 = pTest;
	}

	std::cout << "Finished" << std::endl;

	return 0;
}

