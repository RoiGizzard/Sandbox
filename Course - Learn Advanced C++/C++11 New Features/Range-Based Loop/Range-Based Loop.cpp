#include <iostream>
#include <vector>

int main()
{
    auto texts = { "one", "two", "three" };

    for (auto text : texts)
    {
        std::cout << text << std::endl;
    }

    std::vector<int> numbers = { 4, 5, 6, };
    for (auto number : numbers)
    {
        std::cout << number << std::endl;
    }

    std::string chars = "Hello";
    for (auto c : chars)
    {
        std::cout << c << std::endl;
    }
}
