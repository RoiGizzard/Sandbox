#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> numbers(20);

    cout << "Size : " << numbers.size() << endl;

    int capacity = numbers.capacity();
    cout << "Capacity :  " << capacity << endl;

    for (int i = 0; i < 10000; i++)
    {
        if (numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            cout << "New capacity : " << capacity << endl;
        }
        numbers.push_back(i);
    }

    numbers.clear();
    cout << endl <<  "Clear size : " << numbers.size() << endl;
    cout << "Clear capacity :  " << numbers.capacity() << endl;

    numbers.resize(100);
    cout << endl <<  "Resize size : " << numbers.size() << endl;
    cout << "Resize capacity :  " << numbers.capacity() << endl;

    numbers.reserve(100001);
    cout << endl << "Reserve size : " << numbers.size() << endl;
    cout << "Reserve capacity :  " << numbers.capacity() << endl;

    return 0;
}

