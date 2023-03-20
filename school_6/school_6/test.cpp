#include<iostream>
#include  <cmath>
#include  <iomanip>
using namespace std;

//double getArea(const double& r, const double& pi)
//{
//
//    return  pi * r * r;
//}
//
//
//double getArea(const double &r)
//{
//    const double pi = 3.1415;
//    return  pi * r * r;
//}
//
//
//int main()
//{
//    double  r, pi, area;
//    cin >> r >> pi;
//    if (pi < 0)
//        area = getArea(r);
//    else
//        area = getArea(r,pi);
//        
//    cout.precision(6);
//    cout.setf(ios::fixed | ios::showpoint);
//    cout << area;
//
//
//	system("pause");
//	return 0;
//}


//long  int  fac(int  n)
//{
//    long  int  i, fact = 1;
//    for (i = 1; i <= n; i++)
//        fact *= i;
//
//    return fact;
//    
//}
//
//
//int main()
//{
//
//    long  int  fac(int  n);
//    int  n, m;
//    cin >> n >> m;
//    if (n > m)
//        cout << fac(n) / (fac(n - m) * fac(m)) << endl;
//    else
//        cout << "no" << endl;
//
//    system("pause");
//    return 0;
//}



//void  reverse(int  n)
//{
//    if (n < 0)
//        cout << n;
//    else
//    {
//        cout << n % 10;
//        n /= 10;
//        if (n != 0)
//        {
//            reverse(n);
//        }
//    }
//}
//
//int  main()
//{
//    int  num;
//    cin >> num;
//    reverse(num);
//    return  0;
//}


//extern  int  x, y, z;
//
//int  main()
//{
//    void  sort();
//    cin >> x >> y >> z;
//    cout << "Before  sorting:x=" << x << ",y=" << y << ",z=" << z << endl;
//    sort();
//    cout << "After  sorting:x=" << x << ",y=" << y << ",z=" << z << endl;
//    return  0;
//}
//int  x, y, z;
//void  sort()
//{
//    int  temp;
//    if (y > x)
//    {
//        temp = x;
//        x = y;
//        y = temp;
//    }
//    if (z > y)
//    {
//        temp = y;
//        y = z;
//        z = temp;
//    }
//    if (z > x)
//    {
//        temp = x;
//        x = z;
//        z = temp;
//    }
//    if (x < y || x < z || y < z)
//    {
//        sort();
//    }
//}

//long  factorial(int  n)
//{
//    long k = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        k *= i;
//    }
//
//    return  k;
//}
//
//
//int  main()
//{
//    long  factorial(int  n);
//    int  n, i;
//    long  p;
//    cin >> n;
//    for (i = 1; i <= n; i++)
//    {
//        p = factorial(i);
//
//        cout << "Factorial  of  " << i << "  is  " << p << endl;
//    }
//    return  0;
//}




double  anfun(double  x, int  n)
{
    static  double  an;
    for (int i = 1; i <= n; i++)
    {
        int temp = 2 * i - 1;
        long int m = 1;
        for (int j = 1; j <= temp; j++)
        {
            m *= j;
        }
        an = pow(x, temp) / m;
    }
    
    return  an;
}

#define  ESP  1e-9
#define  PI  3.1415926

int  main()
{
    double  anfun(double  x, int  n);
    double  x0, x, sinx, an;
    int  n, sign;
    cin >> x0;
    x = x0 / 180 * PI;
    sinx = 0;
    sign = 1;
    n = 1;
    an = x;
    while (abs(an) >= ESP)
    {
        sinx += sign * an;
        an = anfun(x, n);
        sign = -sign;
        n++;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << "Results  of  self-made  functions:sin(" << x0 << ")=" << sinx << endl;
    cout << setiosflags(ios::fixed) << setprecision(6) << "Results  of  standard  functions:sin(" << x0 << ")=" << sin(x) << endl;
    return  0;
}