#include  <iostream>
#include <vector>
using  namespace  std;

//typedef  struct  node
//{
//    int  data;
//    struct  node* next;
//}NODE;
//
//NODE* create(int  n)
//{
//    NODE* p, * h;
//    int  i, x;
//    h = new  NODE;
//    h->next = NULL;
//    for (i = n; i > 0; i--)
//    {
//        p = new  NODE;
//        cin >> x;
//        p->data = x;
//
//
//    }
//    return  h;
//}
//
//void  printlist(NODE* h)
//{
//    NODE* current = h;
//    while (current->next != NULL)
//    {
//        current = current->next;
//        cout << current->data << "  ";
//    }
//}
//
//int  main()
//{
//    int  n;
//    NODE* head;
//    cin >> n;
//
//
//    printlist(head);
//    return  0;
//}

//class Student
//{
//public:
//
//	string m_Name;
//	int m_Chinese = 0;
//	int m_Math = 0;
//	int m_English = 0;
//	int total = 0;
//};
//
//
//int main()
//{
//	Student s[10];
//	int i = 0, n, index = 0;
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		cin >> s[i].m_Name >> s[i].m_Chinese >> s[i].m_Math >> s[i].m_English;
//		s[i].total= s[i].m_Chinese + s[i].m_Math + s[i].m_English;
//	}
//
//	int max = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (s[i].total > max)
//		{
//			max = s[i].total;
//			index = i;
//		}
//	}
//
//	cout << s[index].m_Name
//		<< " " << s[index].m_Chinese
//		<< " " << s[index].m_Math
//		<< " " << s[index].m_English << endl;
//
//	system("pause");
//	return 0;
//}

class Student
{
public:

	double calculateTotal()
	{
		return this->Lesson_grade * 0.7 + this->Rest_grade * 0.3;
	}

	void judge()
	{
		if (this->total >= 80 && (this->Lesson_grade + this->Rest_grade) > 140)
		{
			cout << "Excellent" << endl;
		}
		else
		{
			cout << "Not excellent" << endl;
		}
	}

	string ID;
	double Lesson_grade = 0;
	double Rest_grade = 0;
	double total = 0;
};

int main()
{
	Student s[10];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].ID >> s[i].Lesson_grade >> s[i].Rest_grade;
		s[i].total = s[i].calculateTotal();
		s[i].judge();
	}

	system("pause");
	return 0;
}
