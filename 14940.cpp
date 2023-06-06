#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[1001][1001];
int result[1001][1001];
pair<int, int> goal;
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void BFS(int x, int y) {
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        graph[cur.first][cur.second] = 0;

        for (int i = 0; i < 4; i++) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if (isInDomain(nextX, nextY) && graph[nextX][nextY] && result[nextX][nextY] == -1) {
                q.push({nextX, nextY});
                graph[nextX][nextY] = 0;
                result[nextX][nextY] = result[cur.first][cur.second] + 1;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            result[i][j] = -1;
            if (graph[i][j] == 2) {
                q.push({i, j});
                result[i][j] = 0;
            }
            if (graph[i][j] == 0) {
                result[i][j] = 0;
            }
        }
    }

    BFS(0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
