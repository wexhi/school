#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

int distance(int src, int dst,map<int, vector<int>>  &m)
{
	if (src == dst)
	{
		return 0;
	}

	//检测有没有距离为1的
	for (auto i : m[src])
	{
		if (i == dst)
		{
			return 1;
		}
	}

	queue<int> q;

	q.push(src);

	int level = 0;

	while (!q.empty())
	{
		int size = q.size();
		while (size)
		{
			int temp = q.front();
			q.pop();
			for (auto i : m[temp])
			{
				if (i == dst)
				{
					return level + 1;
				}
				q.push(i);
			}
			size--;
		}
		level++;
	}


}


int main()
{
	int n;
	cin >> n;
	int source = 0, destination = 0;

	map<int, vector<int>> m;

	while (n)
	{
		cin >> source >> destination;
		m[source].push_back(destination);
		m[destination].push_back(source); // [1,2] [2,1]
		n--;
	}

	int l;
	cin >> l;

	while (l)
	{
		cin >> source >> destination;
		cout << distance(source, destination, m) << endl;
		l--;
	}

	return 0;
}