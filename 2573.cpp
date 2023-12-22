#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 301

int graph[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int N, M, ans;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];
    }
}

void melting() {
    queue<pii> zeroq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!graph[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

                if (!graph[ny][nx])
                    zeroq.push({i, j});
            }
        }
    }

    while (!zeroq.empty()) {
        auto cur = zeroq.front();
        zeroq.pop();

        if (graph[cur.first][cur.second]) graph[cur.first][cur.second]--;
    }
}

void bfs(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (!graph[ny][nx] || visited[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }
}

void solve() {
    while (1) {
        memset(visited, 0, sizeof(visited));
        int landCnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!graph[i][j] || visited[i][j]) continue;

                bfs(i, j);
                landCnt++;
            }
        }

        melting();

        if (landCnt > 1) { cout << ans << endl; exit(0); }
        if (!landCnt) { cout << 0 << endl; exit(0); }

        ans++;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
