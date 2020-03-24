#include <iostream>

template<class T, class S>
auto test(T a, S b) -> decltype(a + b)
{
    return a + b;
}

int get()
{
    return 999;
}

auto test2() -> decltype(get())
{
    return get();
}

int main()

    auto text = "Hello";
    std::cout << text << std::endl;

    std::cout << test(200, 220) << std::endl;

    std::cout << test2() << std::endl;
}
