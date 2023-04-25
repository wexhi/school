#include <iostream>
#include <queue>
#include<map>
using namespace std;

const int MAXN = 100;
char maze[MAXN][MAXN];
int dist[MAXN][MAXN];
int N, M;

struct Point {
    int x, y;
};

int bfs(Point s, Point g) {
    // 初始化距离数组
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = -1;
        }
    }

    // 定义上下左右四个方向
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    queue<Point> q;
    q.push(s);
    dist[s.x][s.y] = 0;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == g.x && p.y == g.y) {
            return dist[p.x][p.y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && dist[nx][ny] == -1) {
                q.push(Point { nx, ny });
                dist[nx][ny] = dist[p.x][p.y] + 1;
            }
        }
    }

    return -1;  // 无法到达终点
}

int main() {

    cin >> N >> M;

    Point s, g;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                s.x = i;
                s.y = j;
            }
            else if (maze[i][j] == 'G') {
                g.x = i;
                g.y = j;
            }
        }
    }

    int ans = bfs(s, g);
    cout << ans << endl;



    return 0;
}

