#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int v0[3], v1[3], v2[3];
    double dist1, dist2;

    // ��������v0
    cin >> v0[0] >> v0[1] >> v0[2];

    // ��������v1
    cin >> v1[0] >> v1[1] >> v1[2];

    // ��������v2
    cin >> v2[0] >> v2[1] >> v2[2];

    // ����v0��v1֮��ľ���
    dist1 = sqrt(pow(v0[0] - v1[0], 2) + pow(v0[1] - v1[1], 2) + pow(v0[2] - v1[2], 2));

    // ����v0��v2֮��ľ���
    dist2 = sqrt(pow(v0[0] - v2[0], 2) + pow(v0[1] - v2[1], 2) + pow(v0[2] - v2[2], 2));

    // �жϾ����ĸ���������
    if (dist1 < dist2) {
        cout << "v1" << endl;
    }
    else {
        cout << "v2" << endl;
    }

    return 0;
}
