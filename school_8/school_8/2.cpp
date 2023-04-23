#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[101];  // �����ַ���
    cin >> s;  // �����ַ���

    int count[26] = { 0 };  // ��ʼ��һ������Ϊ26�����飬���ڴ洢ÿ����ĸ���ֵĴ���

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            s[i] = toupper(s[i]);  // ת��Ϊ��д��ĸ
            count[s[i] - 'A']++;  // ���¶�Ӧ��ĸ�ĳ��ִ���
        }
    }

    int max_count = 0;  // ��¼���ִ���������ĸ�ĳ��ִ���
    char max_char;  // ��¼���ִ���������ĸ

    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_char = i + 'A';
        }
    }

    cout << max_char << endl;  // ������

    return 0;
}
