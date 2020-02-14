#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string inFileName = "test.txt";
    ifstream inFile;

    inFile.open(inFileName);

    if (inFile.is_open())
    {
        while (inFile)
        {
            string line;
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();
    }
    else
    {
        cout << "Can't open file : " << inFileName << endl;
    }

    return 0;
}
