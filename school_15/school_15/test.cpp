#include<iostream>
#include<cmath>
using namespace std;

class human {
public:
	string name = "小明";
	void print()
	{
		cout << name << endl;
	}
};
class student :public human {
public:
	student(string name)
	{
		this->name = name;
	}
	//string name = "小红";
	void print()
	{
		cout << name << endl;
	}

	string name;
};
int main()
{
	student st("小红");
	st.print();
	return 0;
}
