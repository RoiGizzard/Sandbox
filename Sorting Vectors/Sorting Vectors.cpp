#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Test
{
public:
	Test(int id, string name)
		: id(id),
		  name(name)
	{}

	void print()
	{
		cout << id << " - " << name << endl;
	}

	bool operator<(const Test& other) const
	{
		return name < other.name;
	}

	friend bool comp(const Test& a, const Test& b);

private:
	int id;
	string name;
};

bool comp(const Test &a, const Test &b)
{
	return a.id < b.id;
}

int main()
{
	vector<Test> v;

	v.push_back(Test(4, "Joe"));
	v.push_back(Test(2, "Jeff"));
	v.push_back(Test(3, "Bruno"));
	v.push_back(Test(1, "Pepe"));

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++)
	{
		v[i].print();
	}
}
