#include <iostream>

class Parent
{
public:
	void speak()
	{
		std::cout << "Parent" << std::endl;
	}
};

class Brother : public Parent
{

};

class Sister : public Parent
{

};

int main()
{
	Parent parent;
	Brother brother;

	float value = 2.23;

	std::cout << int(value) << std::endl;
	std::cout << static_cast<int>(value) << std::endl;

	Parent *pParent = &brother;

	Brother *pBrother = static_cast<Brother*>(&parent);
	std::cout << pBrother << std::endl;

	Parent *pParentBrother = &brother;

	Brother *pBrotherBrother = static_cast<Brother*>(pParentBrother);
	std::cout << pBrotherBrother << std::endl;

	Parent &&p = static_cast<Parent &&>(parent);
	p.speak();

	return 0;
}

