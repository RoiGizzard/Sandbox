#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");
	
	for (auto i = 0; i < strings.size(); i++)
	{
		cout << strings[i] << endl;
	}

	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}

	for (auto str : strings)
	{
		cout << str << endl;
	}

	cout << strings.size() << endl;
}