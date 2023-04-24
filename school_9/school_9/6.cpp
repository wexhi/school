#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // 输入 n 和 m
    int a[n][m], b[m][n];  // 定义原数组 a 和转置数组 b

    // 输入原数组 a 的值
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // 将原数组 a 转置到数组 b 中
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }

    // 输出转置数组 b 的值
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
