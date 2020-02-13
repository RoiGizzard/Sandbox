#include <iostream>
using namespace std;

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = false;
    bool error3 = true;

    if (error1)
    {
        throw 8;
    }

    if (error2)
    {
        throw "My chars went wrong";
    }

    if (error3)
    {
        throw string("My string went wrong");
    }
}

void useMightGoWrong()
{
    mightGoWrong();
}

int main()
{
    try 
    {
        useMightGoWrong();
    }
    catch (int e)
    {
        cout << "Error : " << e << endl;
    }
    catch (char const* e)
    {
        cout << "Error : " << e << endl;
    }
    catch (string &e)
    {
        cout << "Error : " << e << endl;
    }

    cout << "Still running" << endl;

    return 0;
}
