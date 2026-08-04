#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int graph[101][101];
int testGraph[101][101];
int n, maxHeight = -1;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
vector<int> result;
int cnt, curHeight;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < n);
}

bool isSink(int x, int y) {
    return testGraph[x][y] <= curHeight;
}

void copyGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            testGraph[i][j] = graph[i][j];
        }
    }
}

void BFS(int x, int y) {
    q.push({x, y});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        testGraph[cur.first][cur.second] = curHeight;

        for (int i = 0; i < 4; i++) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if (!isSink(nextX, nextY) && isInDomain(nextX, nextY)) {
                q.push({nextX, nextY});
                testGraph[nextX][nextY] = curHeight;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            maxHeight = max(maxHeight, graph[i][j]);
        }
    }

    for (int i = 0; i <= maxHeight; i++) {
        copyGraph();
        curHeight = i;
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!isSink(i, j)) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        result.push_back(cnt);
    }
    sort(result.begin(), result.end());
    cout << result[result.size() - 1] << '\n';

    return 0;
}
