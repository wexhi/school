#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<set>
#include <algorithm>
using namespace std;



int main()
{
	ifstream ifs("sort.in",ios::out);
	ofstream ofs("sort.out", ios::out);
	string line, word;
	vector<string> words;

	while (getline(ifs, line))
	{
		stringstream ss(line);
		while (ss >> word)
		{
			words.push_back(word);
		}
	}

	sort(words.begin(), words.end());

	for (size_t i = 0; i < words.size() - 1; i++)
	{
		if (words[i] == words[i + 1])
		{
			words.erase(words.begin() + i);
		}
	}

	//Ð´ÈëÎÄ¼þ
	for (size_t i = 0; i <= words.size() - 1; i++)
	{
		ofs << words[i] << " ";
	}


	ifs.close();
	ofs.close();
	system("pause");

	return 0;
}