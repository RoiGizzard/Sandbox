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

    bool operator==(const Complex& other) const
    {
        return (real == other.real) && (img == other.img);
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

    double getReal() const { return real; }
    double getImg() const { return img; }

private:
    double real;
    double img;
};

ostream& operator<<(ostream& out, const Complex& c)
{
    out << "(" << c.getReal() << "," << c.getImg() << ")" << endl;
    return out;
}

Complex operator+(const Complex& a, const Complex& b)
{
    return Complex(a.getReal() + b.getReal(), a.getImg() + b.getImg());
}

Complex operator+(const Complex& a, double b)
{
    return Complex(a.getReal() + b, a.getImg());
}

Complex operator+(double a, const Complex& b)
{
    return Complex(b.getReal() + a, b.getImg());
}

int main()
{
    Complex c1(2, 3);
    Complex c2(2,5);

    if (c1 == c2)
    {
        cout << "Equal" << endl;
    }

    if (c1 != c2)
    {
        cout << "Not equal" << endl;
    }
}
