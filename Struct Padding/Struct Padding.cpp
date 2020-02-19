#include <iostream>
using namespace std;

// INTING : byte padding

struct PaddedStruct
{
    char name[50];
    int age;
    double weight;
};

#pragma pack(push, 1)
struct NoPaddingStruct
{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main()
{
    cout << "Padded struct size : " << sizeof(PaddedStruct) << endl;
    cout << "No padding struct size : " << sizeof(NoPaddingStruct) << endl;
}
