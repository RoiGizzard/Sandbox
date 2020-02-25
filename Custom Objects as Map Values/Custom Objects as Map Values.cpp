#include <iostream>
#include <map>
using namespace std;

class Person
{
public:
    Person()
        : name(""),
          age(0) 
    {
        cout << "Empty constructor | " << name << " - " << age << endl;
    }

    Person(string name, int age)
        : name(name),
          age(age)
    {
        cout << "Shallow constructor | " << name << " - " << age << endl;
    }

    Person(const Person& other)
    {
        name = other.name;
        age = other.age;
        cout << "Copy constructor | " << name << " - " << age << endl;
    }

    void print() const
    {
        cout << name << " - " << age << endl;
    }

private:
    string name;
    int age;
};

int main()
{
    map<int, Person> people;

    people[0] = Person("Mike", 40);
    people[1] = Person("Joe", 49);
    people[2] = Person("Jeff", 19);

    people.insert(make_pair(55, Person("Bob", 45)));
    people.insert(make_pair(420, Person("Juno", 45)));

    cout << endl;
    for (auto x : people)
    {
        cout << x.first << " - " << flush;
        x.second.print();
    }

    cout << endl;
    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {
        cout << it->first << " - " << flush;
        it->second.print();
    }

    return 0;
}
