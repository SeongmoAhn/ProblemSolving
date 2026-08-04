#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n;
char check;
string graph1[101];
char graph2[101][101];
bool visited1[101][101], visited2[101][101];
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < n);
}

void BFS1(int x, int y) {
    q.push({x, y});
    check = graph1[x][y];
    visited1[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isInDomain(nx, ny) && graph1[nx][ny] == check && !visited1[nx][ny]) {
                q.push({nx, ny});
                visited1[nx][ny] = true;
            }
        }
    }
}

void BFS2(int x, int y) {
    q.push({x, y});
    check = graph2[x][y];
    visited2[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (isInDomain(nx, ny) && graph2[nx][ny] == check && !visited2[nx][ny]) {
                q.push({nx, ny});
                visited2[nx][ny] = true;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> graph1[i]; 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph2[i][j] = (graph1[i][j] == 'B' ? 'B' : 'R');
        }
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited1[i][j]) {
                BFS1(i, j);
                cnt1++;
            }
            if (!visited2[i][j]) {
                BFS2(i, j);
                cnt2++;
            }
        }
    }

    cout << cnt1 << ' ' << cnt2 << '\n';

    return 0;
}
