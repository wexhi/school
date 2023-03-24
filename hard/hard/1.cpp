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
		size_t i = 0, pos = 0;
		while (i < s.size())
		{
			char count = '0';
			if (s[i] == s[i + 1])
			{
				count++;
				i++;
			}
			m_comstr += m_str[i] + count;
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

	system("pause");
	return 0;
}