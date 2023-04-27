#include<iostream>
#include<queue>
using namespace std;



int main()
{
	int n;
	cin >> n;
	queue<int> v;

	int m, temp = 1;
	cin >> m;
	while (m--)
	{
		char op;
		cin >> op;
		if (op == '0' && temp <= n)
		{
			v.push(temp);
			temp++;
		}
		else
		{
			int x = v.front();
			v.pop();
			v.push(x);
		}
	}

	while (!v.empty())
	{
		cout << v.front() << " ";
		v.pop();
	}

	system("pause");
	return 0;
}