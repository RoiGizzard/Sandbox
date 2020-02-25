#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    
    list<int>::iterator a = numbers.begin();
    a++;
    numbers.insert(a, 100);
    cout << "Element : " << *a << endl;

    list<int>::iterator b = numbers.begin();
    b++;
    b = numbers.erase(b);
    cout << "Element after erase: " << *b << endl;

    list<int>::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        if (*it == 2)
        {
            numbers.insert(it, 5);
        }

        if (*it == 1)
        {
            it = numbers.erase(it);
        }
        else
        {
            it++;
        }
    }
    cout << endl;

    for (auto number : numbers)
    {
        cout << number << endl;
    }
    cout << endl;

    return 0;
}
