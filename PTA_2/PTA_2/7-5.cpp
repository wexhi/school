#include <iostream>
#include <cmath>
using namespace std;

// 将n个圆盘从a移动到c，其中可以借助b
long long hanoi(int n, char a, char b, char c)
{
    if (n == 1) {
        // 当只有一个圆盘时，直接从a移动到c
        cout << a << "->" << c << endl;
        return 1;
    }
    else {
        // 将n-1个圆盘从a移动到b
        long long count = hanoi(n - 1, a, c, b);
        // 将最后一个圆盘从a移动到c
        cout << a << "->" << c << endl;
        count++;
        // 将n-1个圆盘从b移动到c
        count += hanoi(n - 1, b, a, c);
        return count;
    }
}

int main()
{
    int n;
    while (cin >> n) {
        // 计算将n个圆盘从A移动到C需要的最小步骤数
        long long count = pow(2, n) - 1;
        // 将n个圆盘从A移动到C，可以借助B
        hanoi(n, 'A', 'B', 'C');
        cout << "共需移动" << count << "次" << endl;
    }
    return 0;
}
