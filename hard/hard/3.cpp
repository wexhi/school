#include<iostream>
#include<string>
#include<vector>
using namespace std;

//将相同的牌排到一起
//void same(vector<string>& s)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		for (int j = i + 1; j < s.size(); j++)
//		{
//			if (s[i] == s[j])
//			{
//				string temp = s[j];
//				s.erase(s.begin() + j);
//				s.insert(s.begin() + i, temp);
//			}
//		}
//	}
//}

//将牌按数字顺序排序
void sortNum(vector<string>& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		for (size_t j = i + 1; j < s.size(); j++)
		{
			if (s[i][0] == s[j][0])
			{
				if (s[i][0] > s[j][0])
				{
					string temp = s[j];
					s.erase(s.begin() + j);
					s.insert(s.begin() + i, temp);

				}
			}
		}
	}
}

//将牌按字母顺序排序
void sortLetter(vector<string>& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		for (size_t j = i + 1; j < s.size(); j++)
		{

			if (s[i][1] > s[j][1])
			{
				string temp = s[j];
				s.erase(s.begin() + j);
				s.insert(s.begin() + i, temp);
			}
			
		}
	}
}

//判断是否胡牌
bool isCardHu(vector<string> s)
{
	int m = 0, n = 0;
	//判断是否三张牌相同
	for (size_t i = 0; i < s.size() - 3; i++)
	{
		if (s[i] == s[i + 1] && s[i] == s[i + 2])
		{
			m++;
			i += 2;
		}
	}
	//判断是否三张牌连续
	size_t index = 0;
	for (size_t i = 0; i < s.size() - 3; i++)
	{
		if (s[i][1] == s[i + 1][1] && s[i][1] == s[i + 2][1])
		{
			if (s[i][0] == (s[i + 1][0] - 1) && s[i][0] == (s[i + 2][0] - 2))
			{
				n++;
				if (m + n == 4)
				{
					index = i;
					break;
				}
				i += 2;
			}
		}
	}
	
	bool flag = false;
	for (; index < s.size() - 1; index++)
	{
		if (s[index] == s[index + 1])
		{
			flag = true;
		}
	}

	if (m + n == 4 && flag == true)
	{
		return true;
	}

	return false;
}


int main()
{
	//输入14张牌
	string s;
	vector<string> sv;
	getline(cin, s);
	//将s非空格的部分写入sv
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > 48 && s[i] < 58)
		{
			sv.push_back(s.substr(i , 2));
		}
	}

	//将相同的牌排到一起
	//same(sv);
	
	//将牌按字母顺序排序
	sortLetter(sv);

	//将牌按数字顺序排序
	sortNum(sv);

	//判断是否胡牌
	if (isCardHu(sv))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	

	//输出sv
	//for (int i = 0; i < sv.size(); i++)
	//{
	//	cout << sv[i] << " ";
	//}


	system("pause");
	return 0;
}