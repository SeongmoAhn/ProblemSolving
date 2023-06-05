#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int m, n, k;
bool graph[101][101];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
vector<int> result;
queue<pair<int, int>> q;
int cnt;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < m) && (y < n);
}

void BFS(int x, int y) {
    q.push({x, y});
    graph[x][y] = 1;
    cnt++;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (isInDomain(nextX, nextY) && graph[nextX][nextY] == 0) {
                q.push({nextX, nextY});
                graph[nextX][nextY] = 1;
                cnt++;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    for (int t = 0; t < k; t++) {
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;
        for (int i = startX; i < endX; i++) {
            for (int j = startY; j < endY; j++) {
                graph[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0) {
                cnt = 0;
                BFS(i, j);
                result.push_back(cnt);
            }     
        }
    }

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}
