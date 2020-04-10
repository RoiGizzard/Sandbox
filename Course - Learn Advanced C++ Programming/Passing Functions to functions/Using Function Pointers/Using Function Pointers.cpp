#include <iostream>
#include <vector>
#include <algorithm>

bool match(std::string a)
{
    return a.size() == 3;
}

int countStrings(const std::vector<std::string>& texts, bool (*func)(std::string a))
{
    auto ctr = 0;
    for (auto text : texts)
    {
        if (func(text))
        {
            ctr++;
        }
    }

    return ctr;
}

int main()
{
    std::vector<std::string> texts { "one", "two", "three"};

    std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;
    std::cout << countStrings(texts, match) << std::endl;

}
