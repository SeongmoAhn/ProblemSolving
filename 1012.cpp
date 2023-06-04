#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int testCase, cnt, n, m, k;
queue<pair<int, int>> q;
int dx[] = {1, -1, 0, 0} , dy[] = {0, 0, 1, -1};

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void BFS(bool (&graph)[51][51], int x, int y) {
    q.push({x, y});
    graph[x][y] = 0;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (graph[nextX][nextY] && isInDomain(nextX, nextY)) {
                graph[nextX][nextY] = 0;
                q.push({nextX, nextY});
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        bool graph[51][51] = {0, };
        cnt = 0;
        cin >> m >> n >> k;
        pair<int, int> p;
        for (int j = 0; j < k; j++) {
            cin >> p.first >> p.second;
            graph[p.second][p.first] = 1;     
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j]) {
                    BFS(graph, i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
