#include <iostream>
#include <vector>
#include <memory>

class Test
{
public:
	Test()
	{
		m_buffer = new int[SIZE] {};
	}

	Test(int i)
	{
		m_buffer = new int[SIZE] {};
		for (int i = 0; i < SIZE; i++)
		{
			m_buffer[i] = 7 * i;
		}
	}

	Test(const Test &other)
	{
		m_buffer = new int[SIZE] {};
		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));
	}

	Test(Test &&other)
	{
		std::cout << "Move constructor" << std::endl;
		m_buffer = other.m_buffer;
		other.m_buffer = nullptr;
	}

	Test &operator = (const Test &other)
	{
		m_buffer = new int[SIZE] {};
		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));
		return *this;
	}

	~Test()
	{
		delete[] m_buffer;
	}

	friend std::ostream &operator<<(std::ostream &out, const Test &test);

private:
	static const int SIZE = 100;
	int* m_buffer{nullptr};
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
	std::vector<Test> vec;
	vec.push_back(Test());

	return 0;
}