#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person
{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

void write()
{
    Person someone = { "Joe", 25, 420.2 };

    string file = "test.bin";

    ofstream out;

    out.open(file, ios::binary);

    if (out.is_open())
    {
        out.write(reinterpret_cast<char*>(&someone), sizeof(Person));

        out.close();
    }
    else
    {
        cout << "Can't create file : " << file << endl;
    }

    cout << "Writing ---" <<                   endl;
    cout << "Name : "     << someone.name   << endl;
    cout << "Age : "      << someone.age    << endl;
    cout << "Weight : "   << someone.weight << endl << endl;
}

void read()
{
    Person someone = {};

    string file = "test.bin";

    ifstream in;

    in.open(file, ios::binary);

    if (in.is_open())
    {
        in.read(reinterpret_cast<char*>(&someone), sizeof(Person));

        in.close();
    }
    else
    {
        cout << "Can't create file : " << file << endl;
    }

    cout << "Reading ---"                   << endl;
    cout << "Name : "     << someone.name   << endl;
    cout << "Age : "      << someone.age    << endl;
    cout << "Weight : "   << someone.weight << endl << endl;
}

int main()
{
    write();
    read();

    return 0;
}