#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100;

// 定义四个方向的偏移量，上下左右
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, m;       // 迷宫的长和宽
int maze[MAXN][MAXN];   // 迷宫地图
int dist[MAXN][MAXN];   // 到起点的距离
int sx, sy, tx, ty;     // 起点和终点坐标

struct Point {
    int x, y;
};

// 判断是否越界或者为障碍物
bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    if (maze[x][y] == 1) {
        return false;
    }
    return true;
}

// BFS搜索
int bfs() {
    memset(dist, -1, sizeof(dist));   // 距离数组初始化为-1
    dist[sx][sy] = 0;   // 起点距离设为0

    queue<Point> q;
    q.push(Point { sx, sy });  // 将起点加入队列

    while (!q.empty()) {
        Point p = q.front();  // 取出队首节点
        q.pop();
        if (p.x == tx && p.y == ty) {  // 如果到达终点，返回最短距离
            return dist[tx][ty];
        }
        for (int i = 0; i < 4; i++) {  // 否则按四个方向扩展
            int nx = p.x + dx[i], ny = p.y + dy[i];  // 新节点坐标
            if (check(nx, ny) && dist[nx][ny] == -1) {
                // 如果新节点可行且没有被访问过
                dist[nx][ny] = dist[p.x][p.y] + 1;  // 更新距离
                q.push(Point { nx, ny });  // 加入队列
            }
        }
    }

    return -1;  // 如果搜索完整个地图都没有到达终点，返回-1
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
