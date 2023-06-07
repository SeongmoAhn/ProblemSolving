#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool graph[101][101];
int result[101][101];
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) &&( y < m);
}

void BFS(int x, int y) {
    q.push({x, y});
    
    while (!q.empty()) {
        auto cur = q.front();
        graph[cur.first][cur.second] = 0;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if (graph[nextX][nextY] && isInDomain(nextX, nextY)) {
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
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            graph[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        }
    }

    result[0][0] = 1;
    BFS(0, 0);
    cout << result[n - 1][m - 1] << '\n';

    return 0;
}
