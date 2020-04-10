#include <iostream>

class Test
{
public:
    Test() = default; // Implicit constructor
    //Test(const Test& other) = default; // Explicit copy constructor
    Test(const Test& other) = delete;
    //Test& operator=(const Test& other) = default;
    Test& operator=(const Test& other) = delete;
    Test(int id)
        : id(id)
    {}

    void print()
    {
        std::cout << id << " " << name << std::endl;
    }

private:
    int id{ 3 };
    std::string name{ "Joe" };
};

int main()
{
    Test t;
    t.print();

    Test t2(12);
    t2.print();
    
    //Test t3 = t; // Not working since operator is deleted
    //t3.print();
}
