#include<iostream>
#include<string>
#include <sstream>
#include <vector>
using namespace std;

//int main()
//{
//	int count = 0;
//	char ch;
//	char str[24];//���������Ⱑ�������֣�
//	
//	cin.getline(str, 24);
//	cin >> ch;
//
//	for (char c : str)
//	{
//		if (c == ch)
//		{
//			count++;
//		}
//	}
//	cout << count;
//
//	system("pause");
//	return 0;
//}

//bool findSame(char src[], char c[], int i)
//{
//	int j = 0;
//	int n = strlen(c);
//	while (n)
//	{
//		if (src[i] == c[j])
//		{
//			i++; j++;
//		}
//		n--;
//	}
//	if (j == strlen(c))
//	{
//		return true;
//	}
//	else 
//		return false;
//}
//
//
//string strChange(char dst[], char src[], char c[])
//{
//	int count = 0;
//	char temp[100];
//	strcpy_s(temp, src);
//	for (int i = 0; i < strlen(src); i++)
//	{
//		if (src[i] == c[0]) 
//		{
//			if (findSame(src, c, i))
//			{
//				for (int j = 0, k = i; j < strlen(dst); j++)
//				{
//					temp[k] = dst[j];
//					k++;
//					count++;
//				}
//				char temp_2[100] ;
//				for (int k = 0, j = i + strlen(c); j <= strlen(src); j++)
//				{
//					temp_2[k] = src[j];
//					j++;
//				}
//				strcat_s(temp, temp_2);
//			}
//		}
//	}
//	return temp;
//}
//
//
//int main()
//{
//	char str1[100], str2[100], str3[100];
//	cin.getline(str1, 100);
//	cin.getline(str2, 100);
//	cin.getline(str3, 100);
//
//	cout << strChange(str3, str1, str2);
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string str, s1, s2;
//    getline(cin, str); // �����ַ���
//    cin >> s1 >> s2; // ���뱻�滻�Ӵ����滻�Ӵ�
//
//    string new_str;
//    size_t pos = 0;
//    while (pos < str.size()) {
//        size_t found = str.find(s1, pos); // ��str�в���s1
//        if (found != string::npos) { // ����ҵ���s1
//            new_str += str.substr(pos, found - pos); // ��ǰ����Ӵ�ƴ�ӵ����ַ�����
//            new_str += s2; // ���滻����Ӵ�ƴ�ӵ����ַ�����
//            pos = found + s1.size(); // �����������
//        }
//        else { // ���û�ҵ�s1
//            new_str += str.substr(pos); // ��ʣ�µ��Ӵ�ƴ�ӵ����ַ�����
//            break; // �˳�ѭ��
//        }
//    }
//
//    cout << new_str << endl; // ����滻����ַ���
//    return 0;
//}



//int main()
//{
//	string tel, arr, index;
//	string num = { "0123456789" };
//	getline(cin, tel);
//	char ch = '9';//��Ϊ��ĿҪ��Ӵ�С�ţ���˴�9��ʼ
//	size_t pos = 0;
//	
//	while (ch >= '0')
//	{
//		size_t found = tel.find(ch);
//		if (found != string::npos)
//		{
//			arr += tel[found];//�ҵ�����ǰ���ַ���ƴ��
//			//tel[found] = -1;
//		}
//		ch--;
//		
//	}
//	
//	//���
//	cout << "int[] arr = new int[]{";
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		cout << arr[i];
//		if (i < arr.size() - 1)
//		{
//			cout << ",";
//		}
//	}
//	cout << "};" << endl;
//
//
//	while (pos < tel.size())
//	{
//		size_t found = arr.find(tel[pos]);//��arr������tel��ͬ��ֵ���ҵ��󷵻��±�
//		if (found != string::npos)
//		{
//			index += num[found];
//		}
//		pos++;
//	}
//
//	//���
//	cout << "int[] index = new int[]{";
//	for (size_t i = 0; i < index.size(); i++)
//	{
//		cout << index[i];
//		if (i < index.size() - 1)
//		{
//			cout << ",";
//		}
//	}
//	cout << "};" ;
//
//	system("pause");
//	return 0;
//}

//int wrong = 0;
//
//void checkID(string id, string weight, string Z, string M, int n)
//{
//	cin>>id;
//	size_t pos = 0;
//	int ret = 0;
//
//	while (pos < 17)
//	{
//		ret += (id[pos] - '0') * weight[pos];
//		pos++;
//	}
//	ret %= 11;
//
//	char last_num = id[17];
//	size_t found = Z.find(ret);
//	char captcha = M[found];
//	if (last_num != captcha)
//	{
//		cout << id << endl;
//
//	}
//	else
//	{
//		wrong--;
//	}
//
//	if (n > 1)
//	{
//		checkID(id, weight, Z, M, n - 1);
//	}
//
//}
//
//
//int main()
//{
//	int n; cin >> n;
//	string weight = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };string Z = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };string M = {"10X98765432"};string id = "";
//	wrong = n;
//
//	checkID(id, weight, Z, M, n);
//
//
//	if (0 >= wrong) //ͨ��ȫ�ֱ���wrong�жϣ��������֤�Ƿ���ȷ
//	{
//		cout << "All passed";
//	}
//
//	system("pause");
//	return 0;
//}


//void findAvailable(string week, string change_week, string target_week)
//{
//	size_t found = week.find(change_week);
//		if (found == string::npos)
//		{
//			cout << "not available";
//			return;
//		}
//		found = week.find(target_week);
//		if (found != string::npos)
//		{
//			cout << "not available";
//			return;
//		}
//		cout << "ok";
//}

//int main()
//{
//	string week, change_week, target_week;
//	getline(cin, week);
//	getline(cin, change_week);
//	getline(cin, target_week);
//	size_t pos = 0;
//	size_t found = week.find('-');
//	while (found != string::npos && pos < week.size())
//	{
//		size_t found = week.find('-', pos);
//		//1-10
//		if (found + 2< week.size() && week[found + 2] < 48 && found != string::npos) 
//		{
//			char ch = week[found + 1] - week[found - 1];
//			char c = week[found + 1];
//			while (ch > 1)
//			{
//				c--;
//				week.erase(found, 1);
//				week.insert(found, " ");
//				week.insert(found, 1, c);
//				week.insert(found, " ");
//				ch--;
//			}
//			pos = found;
//		}
//		//>11
//		else if (week[found - 2] > 48 && found > 2 && found != string::npos)
//		{
//			char ch_gewei = week[found + 2] - week[found - 1];
//			if (ch_gewei < 0)
//			{
//				ch_gewei += 10;
//			}
//			char ch_shiwei = '1';
//			char c = week[found + 2];
//			while (ch_gewei > 1)
//			{
//				if (c == '0')
//				{
//					c = '9';
//				}			
//				week.erase(found, 1);
//				week.insert(found, " ");
//				week.insert(found, 1, c);
//				week.insert(found, 1, ch_shiwei);
//				week.insert(found, " ");
//				ch_gewei--;
//				c--;
//			}
//			pos = found;
//		}
//	}
//
//	findAvailable(week, change_week, target_week);
//
//
//
//	system("pause");
//	return 0;
//}

//// ���ַ������ո�ָ�����ɸ��Ӵ�
//vector<string> split(const string& s) {
//    vector<string> result;
//    stringstream ss(s);
//    string item;
//    while (getline(ss, item, ' ')) {
//        result.push_back(item);
//    }
//    return result;
//}
//
//// �����ֶ�ת��Ϊ��������
//vector<int> expand(const string& s) {
//    vector<int> result;
//    stringstream ss(s);
//    string item;
//    while (getline(ss, item, '-')) {
//        result.push_back(stoi(item));
//    }
//    if (result.size() == 2) {
//        for (int i = result[0]; i <= result[1]; i++) {
//            result.push_back(i);
//        }
//    }
//    return result;
//}
//
//// ����������ת��Ϊ�ַ���
//string join(const vector<int>& nums) {
//    stringstream ss;
//    for (int i = 0; i < nums.size(); i++) {
//        ss << nums[i];
//        if (i != nums.size() - 1) {
//            ss << " ";
//        }
//    }
//    return ss.str();
//}
//
//// ���ַ����е����ֶ�չ�����������飬Ȼ���ٽ���������ϲ���һ���ַ���
//string expand_string(const string& s) {
//    vector<string> tokens = split(s);
//    vector<int> nums;
//    for (const string& token : tokens) {
//        vector<int> tmp = expand(token);
//        nums.insert(nums.end(), tmp.begin(), tmp.end());
//    }
//    return join(nums);
//}
//
//int main() {
//    string s = "1-5 6 15-21";
//    string result = expand_string(s);
//    cout << result << endl; // ��� "1 2 3 4 5 6 15 16 17 18 19 20 21"
//    return 0;
//}



vector<string> split(const string& str)
{
	string temp;
	vector<string> res;
	stringstream ss(str);
	while (getline(ss, temp, ' '))
	{
		res.push_back(temp);
	}
	return res;
}


vector<int> strToInt(const string& str)
{
	vector<int> arr;
	string temp;
	stringstream ss(str);
	while (getline(ss, temp, '-'))
	{
		arr.push_back(stoi(temp));
	}
	if (arr.size() == 2)
	{
		for (int i = arr[0]; i <= arr[1]; i++)
		{
			arr.push_back(i);
		}
	}
	return arr;
}

vector<int> stringToInt(const string& week)
{
	vector<string> str;
	vector<int> arr, res;

	str = split(week);
	
	for (int i = 0; i < str.size(); i++)
	{
		arr = strToInt(str[i]);
		res.insert(res.end(), arr.begin(), arr.end());
	}
	
	return res;
}

void coutVectorInt(const vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i]<< " ";
	}
}

int main()
{
	string week = "1-5 6 15-21";
	//getline(cin, week);
	
	vector<int> res = stringToInt(week);

	coutVectorInt(res);




	
	

	system("pause");
 	return 0;
}