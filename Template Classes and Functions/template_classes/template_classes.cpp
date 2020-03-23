#include <iostream>

template<class T, class K>
class TemplateClass
{
private:
    T m_t;

public:
    TemplateClass(T t)
        : m_t(t)
    {}

    void print()
    {
        std::cout << m_t << std::endl;
    }
};

int main()
{
    TemplateClass<std::string, int> object("I'm an object");
    object.print();
}
