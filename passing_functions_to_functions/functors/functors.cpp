#include <iostream>

struct Test
{
    virtual bool operator()(const std::string& text) = 0;
};

struct MatchTest : public Test
{
    virtual bool operator()(const std::string &text)
    {
        return text == "Some text";
    }
};

void check(const std::string& text, Test &test)
{
    if (test(text))
    {
        std::cout << "Check pass" << std::endl;
    }
    else
    {
        std::cout << "Check fails" << std::endl;
    }
}

int main()
{
    MatchTest functor;

    std::string value = "Some text";

    std::cout << functor(value) << std::endl;

    check("Not some text", functor);
}