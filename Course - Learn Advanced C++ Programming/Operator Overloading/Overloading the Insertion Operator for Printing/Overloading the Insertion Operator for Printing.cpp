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

    const Test& operator=(const Test& other)
    {
        cout << "Assignment operator" << endl;
        return *this;
    }

    friend ostream& operator<<(ostream &out, const Test &test)
    {
        out << test.id << " - " << test.name << endl;
        return out;
    }

private:
    int id;
    string name;
};

int main()
{
    Test test1(10, "joe");
    Test test2(30, "jeff");

    int value = 1 + 2 + 5; // Right - Left associativity
    // << operator -> Left - Right associativity

    cout << test1 << test2 << endl;
}