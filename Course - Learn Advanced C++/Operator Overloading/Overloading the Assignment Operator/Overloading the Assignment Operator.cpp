#include <iostream>
using namespace std;

class Test
{
public:
    Test()
        : id(0),
        name("")
    {}

    Test(int id, string name)
        : id(id),
        name(name)
    {}

    Test(const Test& other)
    {
        cout << "Copy constructor" << endl;
        *this = other;
    }

    void print()
    {
        cout << id << " - " << name << endl;
    }

    const Test& operator=(const Test &other)
    {
        cout << "Assignment operator" << endl;
        return *this;
    }

private:
    int id;
    string name;
};

int main()
{
    Test a(10, "Joe");
    Test b(20, "Jeff");

    a = b;
    a.print();

    Test c;// = a = b;

    c.operator=(a);

    cout << endl;

    // Copy initialization
    Test d = a;
    d.print();
}