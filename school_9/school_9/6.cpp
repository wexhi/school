#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // ���� n �� m
    int a[n][m], b[m][n];  // ����ԭ���� a ��ת������ b

    // ����ԭ���� a ��ֵ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // ��ԭ���� a ת�õ����� b ��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }

    // ���ת������ b ��ֵ
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
