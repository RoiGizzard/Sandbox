#include <iostream>
#include <exception>
using namespace std;

class Food : public exception
{
public:
    virtual const char* what()
    {
        return "Food exception";
    }
};

class Fruit : public Food
{
public:
    virtual const char* what()
    {
        return "Fruit exception";
    }
};

class Peach : public Fruit
{
public:
    virtual const char* what()
    {
        return "Peach exception";
    }
};

void willGoWrong()
{
    bool e1 = false;
    bool e2 = false;
    bool e3 = true;

    if (e1)
    {
        throw Food();
    }
    else if (e2)
    {
        throw Fruit();
    }
    else if (e3)
    {
        throw Peach();
    }
}

int main()
{
    try
    {
        willGoWrong();
    }
    catch (Fruit & e)
    {
        cout << "Catched Fruit : " << e.what() << endl;
    }
    catch (Food & e)
    {
        cout << "Catched Food : " << e.what() << endl;
    }
    catch (Peach & e)
    {
        cout << "Catched Peach : " << e.what() << endl;
    }

    cout << "Still running" << endl;

    return 0;
}
