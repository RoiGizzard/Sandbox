#include <iostream>
#include <typeinfo>

class MyClass
{
};

int main()
{
    std::string value;
    std::cout << typeid(value).name() << std::endl;

    MyClass myClass;
    std::cout << typeid(myClass).name() << std::endl;

    decltype(value) name = "Bob";
    std::cout << name << std::endl;
    std::cout << typeid(name).name() << std::endl;
}
