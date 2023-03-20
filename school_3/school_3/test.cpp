#include<iostream>
#include<cmath>
using namespace std;

//int main()
//{
//	char ch;
//	cin >> ch;
//	cout << " " << " " << ch << endl;
//	cout << " " << ch << ch << ch << endl;
//	cout << ch << ch << ch << ch << ch <<endl;
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//    long  int  x, y, r = 0;
//    int  i;
//    cin >> x;
//    y = x;
//    for (i = 0; y != 0; i++)
//    {
//        r = r * 10 + y % 10;
//        y /= 10;
//    }
//    if (r  == x)
//        cout << x << "是回文数\n";
//    else
//        cout << x << "不是回文数\n";
//    return  0;
//
//	system("pause");
//	return 0;
//}

int  main()
{
    int  m = 1;

    while(1)
    {
        if ((m % 5 == 1) && (m % 6 == 5) && (m % 7 == 4) && (m % 11 == 10))
        {
            break;
        }
        else
            m += 10;

    }
    cout << m;

    return  0;
}