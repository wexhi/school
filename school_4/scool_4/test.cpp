#include<iostream>
using namespace std;

//int main()
//{
//	int a, b, c, min;
//	cin >> a >> b >> c;
//	if (a > b)
//	{
//		min = b;
//		b = a;
//		a = min;
//	}
//	if (a > c)
//	{
//		min = c;
//		c = a;
//		a = min;
//	}
//	if (b > c)
//	{
//		min = c;
//		c = b;
//		b = min;
//
//	}
//
//	cout << a << " " << b << " " << c;
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int min, max, j = 0;
//	int arr[10000] = {0};
//	cin >> min >> max;
//	for (int i = min; i < max; i++)
//	{
//		if (i % 3 == 0 && i % 5 != 0)
//		{
//			arr[j] = i;
//			j++;
//		}
//	}
//	
//	for (int i = 0; i < j; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//
//	system("pause");
//	return 0;
//}
 

////判断是否为闰年
//void YearSeason(const int& year, const int& season)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		cout << "Leap year" << ",";
//		if (3 <= season && 5 >= season)
//		{
//			cout << "Spring";
//		}
//		else if (6 <= season && 8 >= season)
//		{
//			cout << "Summer";
//		}
//		else if (9 <= season && 11 <= season)
//		{
//			cout << "Fall";
//		}
//		else
//		{
//			cout << "Winter";
//		}
//	}
//	/*else if (year %400 == 0)
//	{
//	cout << "Leap year" << ",";
//		if (3 <= season && 5 >= season)
//		{
//			cout << "Spring";
//		}
//		else if (6 <= season && 8 >= season)
//		{
//			cout << "Summer";
//		}
//		else if (9 <= season && 11 <= season)
//		{
//			cout << "Fall";
//		}
//		else
//		{
//			cout << "Winter";
//		}
//	}*/
//	else
//	{
//		cout << "Common year" << ",";
//		if (3 <= season && 5 >= season)
//		{
//			cout << "Spring";
//		}
//		else if (6 <= season && 8 >= season)
//		{
//			cout << "Summer";
//		}
//		else if (9 <= season && 11 <= season)
//		{
//			cout << "Fall";
//		}
//		else
//		{
//			cout << "Winter";
//		}
//	}
//}


//int main()
//{
//	int year, season;
//	cin >> year >> season;
//	YearSeason(year,season);
//
//
//	system("pause");
//	return 0;
//}


//输出1+（1+2）+....+（1+2+....+n）
//int ContinueSum(const int& n)
//{
//	int ret = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			ret = ret + j;
//		}
//	}
//	return ret;
//}

//int main()
//{
//	int n,ret;
//	cin >> n;
//	ret = ContinueSum(n);
//	cout << ret << endl;
//
//	system("pause");
//	return 0;
//}

//输出字母塔
void ABCTower(const int& n)
{
	char ch = 'A';

	//输出正字母塔
	for (int i = 1; i <= n; i++)//i=行数
	{
		int j =  i;

		//每行打相应的空格
		for (; j < n; j++)
		{
			cout << " ";
		}
		int k = 0;

		//输出ABCD
		while (k < i)
		{
			
			cout << ch;
			ch++;
			k++;
		}

		int flag = 0;
		
		//输出CBA
		while(ch > 'A')
		{

			ch--;
			flag++;
			if (flag > 1)
			{
				cout << ch;
			}
		}


		cout << endl;
	}

	//倒字母塔
	for (int i = n + 1; i < 2 * n; i++)
	{
		int j = i - n;
		//每行打对应的空格
		while (j)
		{
			cout << " ";
			j--;
		}

		int k = i;

		//输出ABCD
		while (2 * n- k)
		{
			cout << ch;
			ch++;
			k++;
		}

		int flag = 0;

		//输出CBA
		while (ch > 'A')
		{
			ch--;
			flag++;
			if (flag > 1)
			{
				cout << ch;
			}
		}
		cout << endl;
	}
}


int main()
{
	int a = 1;
	do  
	{
		cout << "请输入一个数字：1.字母塔  0.退出" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "请输入字母塔的行数" << endl;
			int n;
			cin >> n;
			ABCTower(n);
		case 0:
			break;
		default:
			continue;
		}

	}while (a);

	system("pause");
	return 0;
}

