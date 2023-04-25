#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int res;
	cin >> res;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == res)
		{
			cout << "Yes" << endl;
			return 0;
		}
		else if (v[i] < res)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v[i] + v[j] == res)
				{
					cout << "Yes" << endl;
					return 0;
				}
				else if (v[i] < res)
				{
					for (int k = j + 1; k < n; k++)
					{
						if (v[i] + v[j] + v[k] == res)
						{

							cout << "Yes" << endl;
							return 0;
						}
						else if (v[i] + v[j] + v[k] < res)
						{
							for (int l = k + 1; l < n; l++)
							{
								if (v[i] + v[j] + v[k] + v[l] == res)
								{
									cout << "Yes" << endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No" << endl;

	system("pause");
	return 0;
}

//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool backtrack(vector<int>& v, int res, int sum, int start) {
//	if (sum == res) {
//		return true;
//	}
//	if (sum > res) {
//		return false;
//	}
//	for (int i = start; i < v.size(); i++) {
//		if (backtrack(v, res, sum + v[i], i + 1)) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	int res;
//	cin >> res;
//	if (backtrack(v, res, 0, 0)) {
//		cout << "Yes" << endl;
//	}
//	else {
//		cout << "No" << endl;
//	}
//	return 0;
//}
