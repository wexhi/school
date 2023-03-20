#include<iostream>
#include<iomanip>

using namespace std;
#define PI  3.1415926;

//将 char 转化为 int
int CharToInt(const char& p)
{
	int ret = p - '0';
	return ret;
}

int main()
{
	char a, b;

	cin >> a >> b;

	a = CharToInt(a);
	b = CharToInt(b);


	cout << a + b;

	system("pause");
	return 0;
}



//将数字翻转
//int SwitchNum(const int& p)
//{
//	int a = p,temp,ans = 0;
//	while (a)
//	{
//		temp = a%10;
//		ans = ans * 10 + temp;
//		a = a / 10;
//	}
//	return ans;
//}
//
//int main()
//{
//	double r, h, V, S_1,S_2,S;
//	cin >> r >> h;
//	V =  r * r * h * PI;
//	S_1 = 2 * ( r * r) * PI;
//	S_2 = (2 * r * h) * PI;
//	S = S_1 + S_2;
//	cout << fixed << setprecision(4) << V << ',' << S << endl;
//
//
//	system("pause");
//	return 0; 
//}