#include <iostream>

template<class T>
void print(T a)
{
    std::cout << a << std::endl;
}

int main()
{
    print(5); // print<int>(5)
    print("I'm a string"); // print<std::string>("I'm a string")
}
