#include  <iostream>
#include  <string>
#include  <iomanip>
#include	<cmath>
using  namespace  std;
//#define  N  5
//float  prate, avg;  //定义全局变量
//int  maxs;
//void  fun(int  a[]);  //fun函数声明,
//
//int  main()
//{
//    int  i;
//    int  score[N];
//    for (i = 0; i < N; i++)
//        cin >> score[i];
//    fun(score);
//    cout << maxs << endl;
//    cout << setw(6) << setiosflags(ios::fixed) << setprecision(2) << avg << endl;
//    cout << setw(6) << setiosflags(ios::fixed) << setprecision(2) << prate << endl;
//}
//
//void  fun(int  a[])
//{
//    int  i, count = 0, sum = 0;
//    maxs = a[0];
//    for (i = 0; i < N; i++)
//    {
//        if (a[i] >= 60)
//            count++;
//        sum = sum + a[i];
//        if (maxs < a[i])
//        {
//            maxs = a[i];//
//        }      
//    }
//    prate = (float)count / N;
//    avg = (float)sum / N;
//}

//#define v 3
//
//void arrScanf(double arr[v])
//{
//	for (int i = 0; i < v; i++)
//	{
//		cin >> arr[i];
//	}
//}
//
//double findDistance(double v0[v], double v1[v])
//{
//	double x, y, z;
//	x = pow(v0[0], 2) - pow(v1[0], 2);
//	y = pow(v0[1], 2) - pow(v1[1], 2);
//	z = pow(v0[2], 2) - pow(v1[2], 2);
//	return sqrt(abs(x) + abs(y) + abs(z));
//}
//
//int main()
//{
//	double v0[v], v1[v], v2[v];
//	double dis1, dis2;
//	arrScanf(v0);arrScanf(v1);arrScanf(v2);
//
//	dis1 = findDistance(v0, v1);
//	dis2 = findDistance(v0, v2);
//
//	if (dis1 <= dis2)
//	{
//		cout << "v1";
//	}
//	else if (dis1 > dis2)
//	{
//		cout << "v2";
//	}
//	else
//	{
//		cout << "v2";
//	}
//
//	system("pause");
//	return 0;
//}


//int findMost(const char arr[],const int &n)
//{
//	int count[100] = { 0 };
//	int pos = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i] == arr[j] && arr[i] != 0)
//			{
//				count[i]++;
//			}
//		}
//	}
//	int max = count[0]; int i = 0;
//	for ( i = 0; i < 100; i++)
//	{
//		if (count[i] >= max)
//		{
//			max = count[i];
//			pos = i;
//		}
//	}
//	return pos;
//}
//
////int increase(const void* a, const void* b)
////{
////	return *(char*)a - *(char*)b;
////}
//
//
//int main()
//{
//	int i,n = 0;
//	char arr[100] = "";
//	cin >> arr;
//	
//	n = sizeof(arr) / sizeof(arr[0]);
//	//qsort(arr, strlen(arr), sizeof(arr[0]), increase);
//
//
//	i = findMost(arr, n);
//	if (arr[i] >= 97 && arr[i] <= 122) 
//	{
//		arr[i] = arr[i] - 32;
//	}
//	cout << arr[i] << endl;
//
//
//	system("pause");
//	return 0;
//}

//int* turn( int a, const int& n)
//{
//	static int arr[10] = { 0 };
//
//	for (int i = 0; i < 5; i++)
//	{
//		arr[4 - i] = a % 10;
//		a = a / 10;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		arr[5 + i] = arr[i];
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		arr[i] = arr[i + n];
//	}
//	return arr;
//}
//
//int main()
//{
//	
//	int a = 0, n = 0;
//	cin >> a >> n;
//	
//	int* p;
//
//	p = turn(a, n);
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << p[i];
//	}
//
//	system("pause");
//	return 0;
//}


//void printStr(char ch[26], int n, int &flag, const int& con)
//{
//	
//	cout << ch[n - 1];
//	int i = 0;
//	for (i = n; i < flag; i++)
//	{
//		ch[i - 1] = ch[i];
//	}
//	ch[i] = 0;
//	flag--;
//	if (flag >= con + n && flag > 0)
//	{
//		n += con;
//		printStr(ch, n - 1, flag, con);
//	}
//	else if (flag < con + n && flag > 0)
//	{
//		n = n + con - flag;
//		printStr(ch, n - 1, flag, con);
//	}
//	
//
//}

#define ALPHABET 26
//
void printStr(char ch[ALPHABET],	const int& n)
{
	int round = 1, count = 0, index = 0;
	while (round < ALPHABET)
	{
		
		if (index % n == 0)
		{
			cout << ch[index];
			ch[index] = 0;

		}
		

		index++;

		if (index > ALPHABET)
		{
			index = ALPHABET - index;
		}

	}

}

int main()
{
	int n = 1,flag = 26;
	cin >> n;
	char ch[26] = {'A'};
	
	//将ch内的元素变成ABCD----XYZ
	for (int i = 1; i < 26; i++)
	{
		ch[i] = 'A' + i;
	}

	printStr(ch, n);
	


	system("pause");
	return 0;
}
