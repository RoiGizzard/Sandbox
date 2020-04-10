#include <iostream>
using namespace std;

class Complex
{
public:
    Complex()
        : real(0),
         img(0)
    {}

    Complex(double r, double i)
        : real(r),
          img(i)
    {}

    Complex(const Complex& other)
    {
        real = other.real;
        img = other.img;
    } 

    const Complex& operator=(const Complex& other)
    {
        real = other.real;
        img = other.img;
        return *this;
    }

    double getReal() const  { return real; }
    double getImg() const  { return img; }

private:
    double real;
    double img;
};

ostream& operator<<(ostream& out, const Complex& c)
{
    out << "(" << c.getReal() << "," << c.getImg() << ")" << endl;
    return out;
}

int main()
{
    Complex c1(2,3);
    Complex c2(c1); // Copy constructor
    c2 = c1; // assignment operator
    
    cout << c1 << c2;
}
