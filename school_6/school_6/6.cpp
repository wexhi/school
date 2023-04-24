#include  <iostream>
#include  <cmath>
#include<iomanip>
#define  ESP  1e-9
#define  PI  3.1415926
using  namespace  std;

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
    while (
        fabs(an) > ESP
        )
    {
        sinx += sign * an;
        //sinx +=  an;
        an = anfun(x, n);
        sign = -sign;
        n++;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << "Results  of  self-made  functions:sin(" << x0 << ")=" << sinx << endl;
    cout << setiosflags(ios::fixed) << setprecision(6) << "Results  of  standard  functions:sin(" << x0 << ")=" << sin(x) << endl;
    return  0;
}

double  anfun(double  x, int  n)
{
    static  double  an;

    //an = -an;
    an = pow(x, 2 * n + 1) / tgamma(2 * n + 2);
   // an = -an;

    return  an;
}