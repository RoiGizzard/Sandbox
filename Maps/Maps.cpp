#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> ages;
    
    ages["Joe"] = 40;
    ages["Jeff"] = 80;
    ages["Caramel"] = 42;

    pair<string, int> aPair("Pepe", 100);
    ages.insert(aPair);

    ages.insert(make_pair("Bob", 420));

    if (ages.find("Jeff") != ages.end())
    {
        cout << "My boy Jeff" << endl;
    }
    else
    {
        cout << "Not my boy Jeff" << endl;
    }

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        pair<string, int> age = *it;
        cout << "Name : " << age.first << " Age : " << age.second << endl;
    }

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        cout << "Name : " << it->first << " Age : " << it->second << endl;
    }

    return 0;
}
