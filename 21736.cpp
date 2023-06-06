#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char graph[601][601];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
pair<int, int> myPoint;
int cnt;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void BFS(int x, int y) {
    q.push({x, y});

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        if (graph[curX][curY] == 'P')
            cnt++;
        graph[curX][curY] = 'X';
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (graph[nextX][nextY] != 'X' && isInDomain(nextX, nextY)) {
                if (graph[nextX][nextY] == 'P')
                    cnt++;
                q.push({nextX, nextY});
                graph[nextX][nextY] = 'X';
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'I')
                myPoint = {i, j};
        }
    }

    BFS(myPoint.first, myPoint.second);

    if (cnt == 0)
        cout << "TT" << '\n';
    else
        cout << cnt << '\n';

    return 0;
}
