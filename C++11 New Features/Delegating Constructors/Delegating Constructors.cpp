#include <iostream>

class Parent
{
public:
	Parent()
		: Parent("Jeff")
	{
		std::cout << "No parameter parent constructor" << std::endl;
	}

	Parent(std::string t)
	{
		text = t;
		std::cout << "String parent constructor" << std::endl;
	}

private:
	int dogs{5};
	std::string text;
};

class Child : public Parent
{
public:
	Child() = default;
};

int main()
{
	Parent p("Joe");
	Child c;
}
