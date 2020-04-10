#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename = "test.txt";
    ifstream input;

    input.open(filename);

    if (!input.is_open())
    {
        cout << "Can't open file : " << filename << endl;
    }

    while (input)
    {
        string line;
        getline(input, line,':');

        int population;
        input >> population;

        input >> ws;

        cout << line << "--" << population << endl;
    }

    input.close();
}
