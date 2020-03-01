#include <iostream>
using namespace std;

class CanGoWrong
{
public:
	CanGoWrong()
	{
		while (true) {
			new int[100000000ul];
		}
	}
};

int main()
{
	try
	{
		CanGoWrong wrong;
	}
	catch (bad_alloc &e)
	{
		cout << "Caught exception : " << e.what() << endl;
	}
	
	cout << "Still running" << endl;

	return 0;
}