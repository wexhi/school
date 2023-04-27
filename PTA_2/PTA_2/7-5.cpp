#include <iostream>
#include <cmath>
using namespace std;

// ��n��Բ�̴�a�ƶ���c�����п��Խ���b
long long hanoi(int n, char a, char b, char c)
{
    if (n == 1) {
        // ��ֻ��һ��Բ��ʱ��ֱ�Ӵ�a�ƶ���c
        cout << a << "->" << c << endl;
        return 1;
    }
    else {
        // ��n-1��Բ�̴�a�ƶ���b
        long long count = hanoi(n - 1, a, c, b);
        // �����һ��Բ�̴�a�ƶ���c
        cout << a << "->" << c << endl;
        count++;
        // ��n-1��Բ�̴�b�ƶ���c
        count += hanoi(n - 1, b, a, c);
        return count;
    }
}

int main()
{
    int n;
    while (cin >> n) {
        // ���㽫n��Բ�̴�A�ƶ���C��Ҫ����С������
        long long count = pow(2, n) - 1;
        // ��n��Բ�̴�A�ƶ���C�����Խ���B
        hanoi(n, 'A', 'B', 'C');
        cout << "�����ƶ�" << count << "��" << endl;
    }
    return 0;
}
