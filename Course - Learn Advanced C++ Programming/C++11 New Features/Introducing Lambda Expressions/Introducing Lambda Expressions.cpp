#include <iostream>
#include <typeinfo>

void test(void (*pFunc)())
{
    pFunc();
}

int main()
{
    auto func = []() { std::cout << "Hello" << std::endl; };
    func();
    std::cout << typeid(func).name() << std::endl;

    []() { std::cout << "Hi" << std::endl; }();

    test(func);

    test([]() { std::cout << "Hi" << std::endl; });
}
