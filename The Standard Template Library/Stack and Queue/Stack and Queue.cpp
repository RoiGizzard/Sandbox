#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test
{
public: 
    Test(string name)
        : name(name)
    {}

    ~Test()
    {
        //cout << "Test destroyed" << endl;
    }

    void print()
    {
        cout << name << endl;
    }
private:
    string name;
};

int main()
{
    // LIFO
    stack<Test> myStack;

    myStack.push(Test("A"));
    myStack.push(Test("B"));
    myStack.push(Test("C"));

    /*
    * Invalid code, Test is destroyed
    Test &t = myStack.top();
    myStack.pop();
    t.print(); // Ref to destroyed Test
    */

    while (myStack.size() > 0)
    {
        Test& t = myStack.top();
        t.print();
        myStack.pop();
    }

    // FIFO
    queue<Test> myQ;

    myQ.push(Test("A"));
    myQ.push(Test("B"));
    myQ.push(Test("C"));

    cout << endl;
    while (myQ.size() > 0)
    {
        Test& t = myQ.front();
        t.print();
        myQ.pop();
    }
}

