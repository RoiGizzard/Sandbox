#include <iostream>
#include "ring.h"

int main()
{
    ring<std::string> ring(3);

    ring.add("one");
    ring.add("two");
    ring.add("three");
    ring.add("four");

    for (auto i = 0; i < ring.size(); i++)
    {
        std::cout << ring.get(i) << std::endl;
    }

    std::cout << std::endl;

    for (auto it = ring.begin(); it != ring.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    for (auto value : ring)
    {
        std::cout << value << std::endl;
    }
}