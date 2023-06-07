#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100;

// �����ĸ������ƫ��������������
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, m;       // �Թ��ĳ��Ϳ�
int maze[MAXN][MAXN];   // �Թ���ͼ
int dist[MAXN][MAXN];   // �����ľ���
int sx, sy, tx, ty;     // �����յ�����

struct Point {
    int x, y;
};

// �ж��Ƿ�Խ�����Ϊ�ϰ���
bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    if (maze[x][y] == 1) {
        return false;
    }
    return true;
}

// BFS����
int bfs() {
    memset(dist, -1, sizeof(dist));   // ���������ʼ��Ϊ-1
    dist[sx][sy] = 0;   // ��������Ϊ0

    queue<Point> q;
    q.push(Point { sx, sy });  // �����������

    while (!q.empty()) {
        Point p = q.front();  // ȡ�����׽ڵ�
        q.pop();
        if (p.x == tx && p.y == ty) {  // ��������յ㣬������̾���
            return dist[tx][ty];
        }
        for (int i = 0; i < 4; i++) {  // �����ĸ�������չ
            int nx = p.x + dx[i], ny = p.y + dy[i];  // �½ڵ�����
            if (check(nx, ny) && dist[nx][ny] == -1) {
                // ����½ڵ������û�б����ʹ�
                dist[nx][ny] = dist[p.x][p.y] + 1;  // ���¾���
                q.push(Point { nx, ny });  // �������
            }
        }
    }

    return -1;  // ���������������ͼ��û�е����յ㣬����-1
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 3) {
                sx = i;
                sy = j;
            }
            else if (maze[i][j] == 4) {
                tx = i;
                ty = j;
            }
        }
    }

    int ans = bfs();
    if (ans == -1) {
        printf("unreachable\n");
    }
    else {
        printf("%d\n", ans);
    }

    return 0;
}
