#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, y;
int graph[51][51];
int cnt;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
queue<pair<int, int>> q;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void BFS(int x, int y) {
    q.push({x, y});
    graph[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if (graph[nextX][nextY] && isInDomain(nextX, nextY)) {
                q.push({nextX, nextY});
                graph[nextX][nextY] = 0;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);

    while (1) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            return 0;
        }

        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j]) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
