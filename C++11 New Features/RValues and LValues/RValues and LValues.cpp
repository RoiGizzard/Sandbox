#include <iostream>
#include <vector>
#include <memory>

class Test
{
public:
	Test()
	{
		std::cout << "Constructor" << std::endl;
		m_buffer = new int[SIZE] {};
		//memset(m_buffer, 0, sizeof(int)*SIZE);
	}

	Test(int i)
	{
		std::cout << "Parametized constructor" << std::endl;
		m_buffer = new int[SIZE] {};
		for (int i = 0; i < SIZE; i++)
		{
			m_buffer[i] = 7 * i;
		}
	}

	Test(const Test &other)
	{
		std::cout << "Copy constructor" << std::endl;
		m_buffer = new int[SIZE] {};
		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));
	}

	Test &operator = (const Test &other)
	{
		std::cout << "Assignment" << std::endl;
		m_buffer = new int[SIZE] {};
		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));
		return *this;
	}

	~Test()
	{
		std::cout << "Destructor" << std::endl;
		delete[] m_buffer;
	}

	friend std::ostream &operator<<(std::ostream &out, const Test &test);

private:
	static const int SIZE = 100;
	int* m_buffer;
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

	int value1 = 7;
	int *pValue1 = &value1;
	//int *pValue2 = &7;

	Test *pTest1 = &test1;
	//Test *pTest2 = &getTest();

	int *pValue3 = &++value1;
	std::cout << *pValue3 << std::endl;

	//int &pValue4 = &value1++;

	// int*s = &(7 + value1);

	return 0;
}