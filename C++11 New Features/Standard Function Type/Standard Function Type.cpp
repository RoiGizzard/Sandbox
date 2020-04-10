#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

bool check(std::string &s)
{
	return s.size() == 3;
}

class Check
{
public:
	bool operator()(std::string &s)
	{
		return s.size() == 3;
	}
} check1;

void run(std::function<bool(std::string&)> check)
{
	std::string test = "dog";
	std::cout << check(test) << std::endl;
}

int main()
{
	std::vector<std::string> vec{"One", "Two", "Three"};

	auto pLambda = [](std::string s) {return s.size() == 3; };

	int count = std::count_if(vec.begin(), vec.end(), pLambda);
	std::cout << count << std::endl;

	count = std::count_if(vec.begin(), vec.end(), check);
	std::cout << count << std::endl;

	count = std::count_if(vec.begin(), vec.end(), check1);
	std::cout << count << std::endl;

	std::cout << std::endl;

	run(pLambda);
	run(check);
	run(check1);

	std::cout << std::endl;

	std::function<int(int, int)> add = [](int a, int b) { return a + b; };
	std::cout << add(7, 3) << std::endl;
}
