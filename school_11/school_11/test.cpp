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

class Student
{
public:

	string m_Name;
	int m_Chinese = 0;
	int m_Math = 0;
	int m_English = 0;
};

int findMax(vector<int> a)
{
	int max_index = 0;
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			max_index = i;
		}
	}
	return max_index;
}

int main()
{
	Student s[10];
	vector<int> arr;
	int i = 0, n, index = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i].m_Name >> s[i].m_Chinese >> s[i].m_Math >> s[i].m_English;
		arr.push_back(s[i].m_Chinese + s[i].m_Math + s[i].m_English);
	}

	//找出最大值下标
	index = findMax(arr);

	cout << s[index].m_Name
		<< " " << s[index].m_Chinese
		<< " " << s[index].m_Math
		<< " " << s[index].m_English << endl;

	system("pause");
	return 0;
}