#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 51

int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int N, L, R, ans;

void initInput() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
}

void solve() {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visited[i][j] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;

                queue<pii> q;
                vector<pii> v;
                visited[i][j] = 1;
                q.push({i, j});
                v.push_back({i, j});
                int sum = 0;

                while (!q.empty()) {
                    auto cur = q.front();
                    sum += map[cur.first][cur.second];
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nY = cur.first + dy[k];
                        int nX = cur.second + dx[k];

                        if (visited[nY][nX] || nY < 0 || nX < 0 || nY >= N || nX >= N) continue;
                        if (abs(map[cur.first][cur.second] - map[nY][nX]) < L
                        || abs(map[cur.first][cur.second] - map[nY][nX]) > R) continue;

                        flag = 1;

                        visited[nY][nX] = 1;
                        q.push({nY, nX});
                        v.push_back({nY, nX});
                    }
                }

                for (int k = 0; k < v.size(); k++) {
                    auto cur = v[k];
                    map[cur.first][cur.second] = sum / v.size();
                }
            }
        }

        if (flag) ans++;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
    cout << ans << endl;
}
