#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[1001][1001];
int result[1001][1001];
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int zeroCnt, maxCnt;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void BFS() {
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if (graph[nextX][nextY] == 0 && isInDomain(nextX, nextY)) {
                q.push({nextX, nextY});
                graph[nextX][nextY] = 1;
                result[nextX][nextY] = result[cur.first][cur.second] + 1;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                result[i][j] = -1;
            if (graph[i][j] == 1) {
                q.push({i, j});
                result[i][j] = 0;
                zeroCnt++;
            }
        }
    }

    BFS();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == 0) {
                zeroCnt--;
            }
            maxCnt = max(maxCnt, result[i][j]);
        }
    }
    if (zeroCnt != 0) {
        cout << -1 << '\n';
    }
    else
        cout << maxCnt << '\n';

    return 0;
}
