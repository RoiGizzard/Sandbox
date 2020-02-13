#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
	virtual const char* what()
	{
		return "MyException occured!";
	}
};

class MyObject
{
public:
	void goWrong()
	{
		throw MyException();
	}
};

int main()
{
	MyObject obj;

	try {
		obj.goWrong();
	}
	catch (MyException & e)
	{
		cout << "Error : " << e.what() << endl;
	}

	cout << "Still running" << endl;

	return 0;
}

