#include <iostream>

template<class T>
void print(T a)
{
    std::cout << "Template version : " << a << std::endl;
}

void print(int a)
{
    std::cout << "Non-template version : " << a << std::endl;
}

template<class T>
void show()
{
    std::cout << "No inference version : " << T() << std::endl;
}

int main()
{
    print(5);
    print<>(5);
    print<int>(5);

    // show(); // Error
    show<int>();
}
 