#include<iostream>
#include<vector>
using namespace std;

//判断是否是回文数
bool isPalindrome(const string& str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return false;
	}
	return true;
}



int main()
{
	string str;
	cin >> str;
	
	if (isPalindrome(str))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");
	return 0;
}