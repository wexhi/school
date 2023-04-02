#include<iostream>
#include<iomanip>
using namespace std;

class  Complex
{
public:
    Complex(double  r, double  i) : real(r), image(i)
    {
    }
    Complex(double  r) : real(r), image(0)
    {
    }
    Complex  operator+(const  Complex& c2)
    {
        this->real  +=  c2.real;
        this->image  +=  c2.image;
        return  *this;
    }
    friend  ostream& operator<<(ostream& out, const  Complex& c2)
    {
        if (c2.image > 0) 
        {
            out << fixed << setprecision(2) << c2.real / 1.00 << "+" << fixed << setprecision(2) << c2.image << "i";
        }
        else
        {
            out << fixed << setprecision(2) << c2.real << fixed << setprecision(2) << c2.image << "i";
        }
        return out;
    }

private:
    double  real;
    double  image;
};

int  main()
{
    float  a, b;
    cin >> a >> b;
    Complex  c1(a, b);
    cin >> a >> b;
    Complex  c2(a, b);
    cout << c1 << endl;
    cout << c2 << endl;
    c1 = c1 + c2;
    cout << c1;
    return  0;
}