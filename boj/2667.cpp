#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> houseCnt;
vector<string> graph(26);
bool visited[26][26];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int cnt, n;

bool isInDomain(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

void BFS(int x, int y) {
    q.push({x, y});
    visited[x][y] = 1;
    cnt++;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (isInDomain(nextX, nextY) && !visited[nextX][nextY] && graph[nextX][nextY] == '1') {
                q.push({nextX, nextY});
                visited[nextX][nextY] = 1;
                cnt++;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> graph[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == '1' && !visited[i][j]) {
                cnt = 0;
                BFS(i, j);
                houseCnt.push_back(cnt);
            }
        }
    }

    sort(houseCnt.begin(), houseCnt.end());
    cout << houseCnt.size() << '\n';
    for (int i = 0; i < houseCnt.size(); i++) {
        cout << houseCnt[i] << '\n';
    }

    return 0;
}
