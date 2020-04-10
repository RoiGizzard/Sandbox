#include <iostream>

class Test
{
public:
	void run()
	{
		int three{ 3 };
		int four{ 4 };

		auto pLambda = [&, this]() {
			one = 10;
			std::cout << one << "," << two << "," << three << "," << four << std::endl;
		};

		pLambda();
	}

private:
	int one{ 1 };
	int two{ 2 };
};

int main()
{
	Test test;
	test.run();
}

