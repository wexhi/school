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
 

////�ж��Ƿ�Ϊ����
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


//���1+��1+2��+....+��1+2+....+n��
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

//�����ĸ��
void ABCTower(const int& n)
{
	char ch = 'A';

	//�������ĸ��
	for (int i = 1; i <= n; i++)//i=����
	{
		int j =  i;

		//ÿ�д���Ӧ�Ŀո�
		for (; j < n; j++)
		{
			cout << " ";
		}
		int k = 0;

		//���ABCD
		while (k < i)
		{
			
			cout << ch;
			ch++;
			k++;
		}

		int flag = 0;
		
		//���CBA
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

	//����ĸ��
	for (int i = n + 1; i < 2 * n; i++)
	{
		int j = i - n;
		//ÿ�д��Ӧ�Ŀո�
		while (j)
		{
			cout << " ";
			j--;
		}

		int k = i;

		//���ABCD
		while (2 * n- k)
		{
			cout << ch;
			ch++;
			k++;
		}

		int flag = 0;

		//���CBA
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
		cout << "������һ�����֣�1.��ĸ��  0.�˳�" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "��������ĸ��������" << endl;
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

