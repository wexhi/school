#include<iostream>
#include<queue>
using namespace std;



int main()
{
	int n;
	cin >> n;
	queue<int> v;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 0 && v.size() != 0)
		{
			//输出第一个数，并删除
			cout << v.front() << endl;
			v.pop();
		}
		else if (op == 1)
		{
			int d;
			cin >> d;
			v.push(d);
		}
		else
		{
			cout << "invalid" << endl;
		}

	}


	system("pause");
	return 0;
}