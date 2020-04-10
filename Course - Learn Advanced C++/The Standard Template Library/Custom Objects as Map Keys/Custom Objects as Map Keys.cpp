#include <iostream>
#include <map>
using namespace std;

class Person
{
public:
    Person()
        : name(""),
        age(0)
    {}

    Person(string name, int age)
        : name(name),
        age(age)
    {}

    Person(const Person& other)
    {
        name = other.name;
        age = other.age;    
    }

    void print() const
    {
        cout << name << " - " << age << endl;
    }

    bool operator<(const Person& other) const
    {
        if (name == other.name)
        {
            return age < other.age;
        }
        else
        {
            return name < other.name;
        }
    }

private:
    string name;
    int age;
};

int main()
{
    map<Person, int> people;

    people[Person("Mike", 40)] = 1;
    people[Person("Mike", 444)] = 123;
    people[Person("Joe", 49)] = 2;
    people[Person("Jeff", 19)] = 3;

    for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
    {
        cout << it->second << " - " << flush;
        it->first.print();
    }

    return 0;
}
