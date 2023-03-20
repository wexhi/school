#include  <iostream>
#include<iomanip>
using  namespace  std;

//int getMax(const int& a, const int& b, const int& c, const int& d)
//{
//    int  x, y;
//    x = a > b ? a : b;
//    y = c > d ? c : d;
//    return  x > y ? x : y;
//}
//
//int getMax(const int& a, const int& b, const int& c)
//{
//    int  x;
//    x = a > b ? a : b;
//    return  x > c ? x : c;
//}
//
//int getMax(const int& a, const int& b)
//{
//    return  a > b ? a : b;
//}
//
//int  main()
//{
//    int  i, j, k, m, n;
//    cin >> i;
//    if (i == 2) {
//        cin >> j >> k;
//        cout << getMax(j, k);
//    }
//    else  if (i == 3) {
//        cin >> j >> k >> m;
//        cout << getMax(j, k, m);
//    }
//    else  if (i == 4) {
//        cin >> j >> k >> m >> n;
//        cout << getMax(j, k, m, n);
//    }
//    return  0;
//}

//#define  PI  3.1415926
//template<class  T>
//
//int getPerimeter(T r1)
//{
//    int ret = 2 * r1 * PI;
//    return ret;
//}
//
//double getPerimeter(double r2)
//{ 
//    
//    return 2 * r2 * PI;
//}
//
//int  main()
//{
//    int  i, r1;
//    double  r2;
//    cin >> i;
//    if (i == 0) {
//        cin >> r1;
//        cout << getPerimeter(r1);
//    }
//    else {
//        cin >> r2;
//        cout.precision(6);
//        cout.setf(ios::fixed | ios::showpoint);
//        cout << getPerimeter(r2);
//    }
//    return  0;
//}


//int  getDaysInMonth(int  month)
//{
//    switch (month) {
//    case  1:
//    case  3:
//    case  5:
//    case  7:
//    case  8:
//    case  10:
//    case  12:
//        return  31;
//    case  4:
//    case  6:
//    case  9:
//    case  11:
//        return  30;
//    }
//}
//
//int  getDaysInMonth(int month,int year)
//{
//    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//        return  29;
//    else
//        return  28;
//}
//
//int  main()
//{
//    int  m, y;
//    cin >> y >> m;
//    if (m == 2)
//        cout << getDaysInMonth(m, y);
//    else
//        cout << getDaysInMonth(m);
//    return  0;
//}


//void  func(int  num)
//{
//    int  i;
//    for (i = 2; i <= num / 2; i++)
//        if (num % i == 0)
//        {
//            cout << i << "*";
//            num /= i;
//            func(num);
//            i = 100;
//            break;
//        }
//    if (num <= 7  && i == 100 || num == 3)
//        cout << num;
//}
//int  main() {
//    int  num;
//    cin >> num;
//    cout << num << "=";
//    func(num);
//    return  0;
//}


//int  pailie(int  m, int  n)
//{
//    if (m == 0)
//        return  1;
//    if (n == 0)
//        return  1;
//
//    //通过递归实现排列组合，每次n-1，例如：C 3 8 ==（8*7*6）/（3*2*1）；也可以写成m-1，m
//    return ((m + n) * pailie(m , n - 1)) / n; 
//}
//int  main()
//{
//    int  m, n;
//    cin >> m >> n;
//    int  type = 0;
//    type = pailie(m, n);
//    cout << type;
//    return  0;
//}


int  main()
{
    int  m, n, r;
    int  gcd_recusion(int  m, int  n);
    cin >> m >> n;
    r = gcd_recusion(m, n);
    cout << "gcd=" << r << endl;
    return  0;
}

int  gcd_recusion(int  m, int  n)
{
    int  k;
    k = m % n;
    if (k == 0)
        return  n;
    else
    {
        m = n;
        n = k;
        return gcd_recusion(m, n);
    }
}