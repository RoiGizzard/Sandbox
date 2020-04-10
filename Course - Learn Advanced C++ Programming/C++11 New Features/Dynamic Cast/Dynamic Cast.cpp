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

	Parent *pParentBrother = &brother;

	Brother *pBrotherBrother = dynamic_cast<Brother*>(pParentBrother);

	if (pBrotherBrother == nullptr)
	{
		std::cout << "Invalid cast" << std::endl;
	}
	else
	{
		std::cout << pBrotherBrother << std::endl;
	}


	return 0;
}

