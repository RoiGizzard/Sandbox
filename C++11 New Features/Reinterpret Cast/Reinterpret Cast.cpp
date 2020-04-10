#include <iostream>

class Parent
{
public:
	virtual void speak()
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
	Sister sister;

	Parent *pParentBrother = &brother;

	Sister *pSisterBrother = reinterpret_cast<Sister*>(pParentBrother);

	if (pSisterBrother == nullptr)
	{
		std::cout << "Invalid cast" << std::endl;
	}
	else
	{
		std::cout << pSisterBrother << std::endl;
	}


	return 0;
}

