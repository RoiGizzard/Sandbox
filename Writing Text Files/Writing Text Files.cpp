#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string outFileName = "test.txt";

    //ofstream outFile;
    //outFile.open(outFileName);

    fstream outFile;
    outFile.open(outFileName, ios::out);

    if (outFile.is_open())
    {
        outFile << "Hello file" << endl;
        for (int x = 0; x < 10; x++)
        {
            outFile << x << endl;
        }

        outFile.close();
    }
    else
    {
        cout << "Could not create file : " << outFileName << endl;
    }
}
