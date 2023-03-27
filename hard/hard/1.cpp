#include<iostream>
#include<string>

using namespace std;

class CompressString
{
public:
	string m_str;
	string m_comstr;
	
	void findSame()
	{
		string s = this->m_str;
		size_t i = 0;
		char count = '1';
		while (i < s.size())
		{

			if (s[i] == s[i + 1])
			{
				count++;
				i++;
			}
			else
			{
				m_comstr += s[i];
				m_comstr += count;
				count = '1';
				i++;
			}

		}
	}
	
	
	CompressString(const string& str)
	{
		m_str = str;
	}
};

int main()
{
	string str;
	getline(cin, str);
	CompressString s(str);
	s.findSame();
	cout << s.m_comstr << endl;
	system("pause");
	return 0;
}