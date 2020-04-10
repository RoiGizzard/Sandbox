#include <iostream>

void print(int a)
{
    std::cout << a << std::endl;
}

int main()
{
    print(10);

    void (*printPtr)(int) = print;
    printPtr(20);
}
