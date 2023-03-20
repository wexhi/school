#include<iostream>
#include<iomanip>
using namespace std;

//int main()
//{
//	int n;
//	double temp,s,sum = 0;
//	cin >> s >> n;
//	temp = s;
//	while (n)
//	{
//		sum += temp;
//		s = s / 4;
//		temp = s * 2;
//		n--;
//	}
//
//	cout << fixed << setprecision(2) << sum << endl;
//	cout << fixed << setprecision(2) << s;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i,n;
//	cin >> n;
//	for (i = 11; i < 100; i++)
//	{
//		int temp = i % 10;
//		temp = temp * 10 + i / 10;
//		if (i * temp == n)
//		{
//			break;
//		}
//	}
//	if (i < 100)
//	{
//		cout << i << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//	system("pause");
//	return 0;
//}

//¼ä¸ô2³Ë
long long product( double& n)
{
	long long temp = 1,ret = 1;

	//while (temp < 2 * n)
	//{
	//	ret *= temp;
	//	temp += 2;
	//	
	//}

	for (int i = 0; i <= n; i++)
	{
		ret *= temp;
		temp += 2;
	}

	return ret;
}


//½×³Ë
long long factorial(double& n)
{ 
	long long temp = 1;
	for (int i = 1; i <= n; i++)
	{
		temp *= i;
	}
	return temp;
}


int main()
{
	//double* pi_arr = new double[30];
	double pi_arr[30] = { 0 };
	pi_arr[0] = 1;
	pi_arr[1] = 4.00 / 3;
	//pi_arr[2] = pi_arr[1] + 2.00 / 15;
	int i = 1;
	double e,fac,n = 2;
	cin >> e;

	while (pi_arr[i] - pi_arr[i - 1] > e / 2.00)
	{
		fac = factorial(n);
		pi_arr[i + 1] = pi_arr[i] + double(fac / product(n));
		i++;
		n++;
	}
	cout << i + 1 << " " << 2.00 * pi_arr[i];

	//if (pi_arr != NULL)
	//{
	//	delete[] pi_arr;
	//	pi_arr = NULL;
	//}

	system("pause");
	return 0;
}