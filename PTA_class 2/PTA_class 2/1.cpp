#include <stdio.h>
using namespace std;
int Gcd(int a, int b);
int main()
{
    int a, b, c;
    scanf_s("%d %d", &a, &b);
    c = Gcd(a, b);
    if (c != -1)
    {
        printf("%d\n", c);
    }
    else
    {
        printf("Input Data error!\n");
    }
    return 0;
}

/* 请在这里完成 Gcd 函数*/
int Gcd(int a, int b)
{
    if (a <= 0 || b <= 0)
    {
		return -1;
	}
    if (a > b)
    {
        return Gcd(a - b,b);
    }
    if (a < b)
    {
        return Gcd(a, b - a);
    }
    if (a == b)
    {
        return a;
    }
}