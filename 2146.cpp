#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, cnt = 2, minValue = 100000, check;
int graph[MAX][MAX];
queue<pair<int, int>> q;
vector<pair<int, int>> v;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < n);
}

void initBFS(int x, int y) {
    q.push({x, y});
    graph[x][y] = cnt;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        check = 0;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isInDomain(nx, ny) && graph[nx][ny] == 1) {
                q.push({nx, ny});
                graph[nx][ny] = cnt;
            }
            else if (isInDomain(nx, ny) && graph[nx][ny] == 0) {
                check = 1;
            }
        }
        if (check)
            v.push_back(cur);
    }
}

void solve() {
    for (int i = 0; i < v.size() - 1; i++) {
        auto cur = v[i];

        for (int j = i + 1; j < v.size(); j++) {
            auto next = v[j];

            if (graph[cur.first][cur.second] != graph[next.first][next.second]) {
                int distance = (abs)(cur.first - next.first) + (abs)(cur.second - next.second) - 1;
                
                minValue = min(distance, minValue);
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
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                initBFS(i, j);
                cnt++;
            }
        }
    }

    solve();
    cout << minValue << '\n';

    return 0;
}
