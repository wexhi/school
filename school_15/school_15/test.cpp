#include<iostream>
#include<cmath>
using namespace std;

class human {
public:
	string name = "С��";
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
	//string name = "С��";
	void print()
	{
		cout << name << endl;
	}

	string name;
};
int main()
{
	student st("С��");
	st.print();
	return 0;
}
