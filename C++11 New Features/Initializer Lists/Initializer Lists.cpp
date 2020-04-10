#include <iostream>
#include <vector>
#include <initializer_list>

class Test
{
public:
    Test(std::initializer_list<std::string> texts)
    {
        for (auto text : texts)
        {
            std::cout << text << std::endl;
        }
    }

    void print(std::initializer_list<std::string> texts)
    {
        for (auto text : texts)
        {
            std::cout << text << std::endl;
        }
    }
};

int main()
{
    std::vector<int> n{ 1, 2, 3, 4, 5 };
    std::cout << n[2] << std::endl;

    Test test{ "One", "Two", "Three" };
    test.print({ "Apple", "Orange", "Banana" });
}
