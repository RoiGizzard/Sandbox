#include <iostream>

class Parent
{
public:
    Parent()
        : a(0)
    {}

    Parent(const Parent& other)
    {
        a = other.a;
        std::cout << "Copy parent" << std::endl;
    }

    virtual void print()
    {
        std::cout << "Parent" << std::endl;
    }
private:
    int a;
};

class Child : public Parent
{
public:
    Child()
        : b(1)
    {}

    void print()
    {
        std::cout << "Child" << std::endl;
    }

private:
    int b;
};

int main()
{
    Child c;
    Parent& p = c;
    p.print();
    
    Parent p2 = Child();
    p2.print();
}
