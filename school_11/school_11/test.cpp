#include  <iostream>
#include <vector>
using  namespace  std;

typedef  struct  node
{
    int  data;
    struct  node* next;
}NODE;

NODE* create(int  n)
{
    NODE* p, * h;
    int  i, x;
    h = new  NODE;
    h->next = NULL;
    for (i = n; i > 0; i--)
    {
        p = new  NODE;
        cin >> x;
        p->data = x;
        p->next = h->next;
        h->next = p;
    }
    return  h;
}

void  printlist(NODE* h)
{
    NODE* current = h;
    while (current->next != NULL)
    {
        current = current->next;
        cout << current->data << "  ";
    }
}

int  main()
{
    int  n;
    NODE* head;
    cin >> n;
    head = create(n);
    
    printlist(head);
    return  0;
}

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

//class Student
//{
//public:
//
//	double calculateTotal()
//	{
//		return this->Lesson_grade * 0.7 + this->Rest_grade * 0.3;
//	}
//
//	void judge()
//	{
//		if (this->total >= 80 && (this->Lesson_grade + this->Rest_grade) > 140)
//		{
//			cout << "Excellent" << endl;
//		}
//		else
//		{
//			cout << "Not excellent" << endl;
//		}
//	}
//
//	string ID;
//	double Lesson_grade = 0;
//	double Rest_grade = 0;
//	double total = 0;
//};
//
//int main()
//{
//	Student s[10];
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s[i].ID >> s[i].Lesson_grade >> s[i].Rest_grade;
//		s[i].total = s[i].calculateTotal();
//		s[i].judge();
//	}
//
//	system("pause");
//	return 0;
//}



//#define MAX 10000
//#define MIN 10
//
////判断是否为质数
//bool isPrime(int n)
//{
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
////算出独立性
//int independent(int num, int flag)
//{
//	int temp = num;
//	int ret = 0;
//	while (num)
//	{
//		temp = num % 10;
//		ret += temp * temp;
//		num /= 10;
//	}
//	flag++;
//	if (ret != 1)
//	{
//		flag = independent(ret, flag);
//	}
//	return flag;
//}
//
////算出独立性数组
//vector<int> independentArr(vector<int> arr)
//{
//	vector<int> ans;
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		bool x = isPrime(arr[i]);
//		if ( x == true)
//		{
//			ans.push_back(2 * independent(arr[i], 0));
//		}
//		else
//		{
//			ans.push_back(independent(arr[i], 0));
//		}
//	}
//	return ans;
//}
//
////当数组中的元素经过迭代时，若与数组中的其他元素相同，删除迭代时出现的相同元素
//int cutDown(int num, vector<int> arr)
//{
//	int temp = num;
//	int ret = 0;
//	int ans = -1;
//	while (num)
//	{
//		temp = num % 10;
//		ret += temp * temp;
//		num /= 10;
//	}
//	if (ret != 1)
//	{
//		for (size_t i = 0; i < arr.size(); i++)
//		{
//			if (ret == arr[i])
//			{
//				
//				return i;
//			}
//		}
//		ans = cutDown(ret, arr);
//	}
//	else
//	{
//		return ans;
//	}
//	return ans;
//}
//
////判断是否依附其他幸福数
//vector<int> isAdhere(vector<int> arr)
//{
//	int index = -1;
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		index = cutDown(arr[i], arr);
//		if (index >= 0)
//		{
//			arr.erase(arr.begin() + index);
//		}
//	}
//	return arr;
//}
//
//bool iterative(int num, int flag)
//{
//	int temp = num;
//	int ret = 0;
//	while (num)
//	{
//		temp = num % 10;
//		ret += temp * temp;
//		num /= 10;
//		flag--;
//	}
//	if (ret == 1)
//	{
//		return true;
//	}
//	if (flag > 0)
//	{
//		iterative(ret, flag);
//	}
//	else
//	{
//		return false;
//	}
//}
//
////判断是否为幸福数
//vector<int> IsHappiness(const int& min, const int& max)
//{
//	vector<int> res;
//	for (int i = min; i < max; i++)
//	{
//		if (iterative(i, 20) == true)
//		{
//			res.push_back(i);
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> res,ind;
//	int A = MIN, B = MAX;
//	cin >> A >> B;
//	
//	//判断是否为幸福数
//	res = IsHappiness(A, B);
//	
//	//判断是否依附其他幸福数
//	res = isAdhere(res);
//	
//	//算出独立性数组
//	ind = independentArr(res);
//	if (res.size() == 0)
//	{
//		cout << "SAD";
//	}
//	else
//	{
//		for (size_t i = 0; i < res.size(); i++)
//		{
//			cout << res[i] << " " << ind[i] << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}