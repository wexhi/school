#include  <iostream>
#include  <iomanip>
#include  <cstring>
#include  <cmath>
using  namespace  std;
//int  isPalStr(char* x);
//int  main()
//{
//    char  ch[100];
//    char* x;
//    x = ch;
//    int  flag;
//    cin >> ch;
//    flag = isPalStr(x);
//    if (flag == 1)
//        cout << ch << "是回文";
//    else
//        cout << ch << "不是回文";
//    return  0;
//}
//int  isPalStr(char* x)
//{
//    int  i, j;
//    i = 0, j = strlen(x) - 1;
//    while (i <= j)
//    {
//        if (*(x + i) != *(x + j) )
//            return  -1;
//        i++, j--;
//    }
//    return  1;
//}


#define  N  10
int  DelInt(int* s, int  c);
int  main()
{
    int  s[] = { 1,  2,  3,  3,  7,  6,  7,  7,  8,  9 }, c, n;
    cin >> c;
    cout << "删除前:";
    for (int i = 0; i < N; i++)
        cout << s[i] << "  ";
    n = DelInt(s, c);
    cout << "\n删除后:";
    for (int i = 0; i < N - n; i++)
        cout << s[i] << "  ";
    return  0;
}
int  DelInt(int* s, int  c)
{
    int  flag = 0, k = 0;
    for (int n = 0; n < N; n++, s++)
        if (*s == c)
        {
            k = 0;
            while (k < N - n)
            {
                s[k] = s[k + 1];
                k++;
            }
            flag = 1;
            return flag;

        }
    return  flag;
}