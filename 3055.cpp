#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define INF 1e9
#define SIZE 51

int N, M, ans;
pii start, _end;
char graph[SIZE][SIZE];
int waterGraph[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
queue<pii> waterQ;


void initInput() {
    cin >> N >> M;
    fill(&waterGraph[0][0], &waterGraph[N][M], INF);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'S') start = {i, j};
            if (graph[i][j] == 'D') _end = {i, j};
            if (graph[i][j] == '*') {
                waterGraph[i][j] = 0;
                waterQ.push({i, j});
            }
        }
}

bool isDomain(int y, int x) { return (y >= 0) && (x >= 0) && (y < N) && (x < M); }
bool canMove(int y, int x) { return isDomain(y, x) && graph[y][x] != 'X'; }

void bfs() {
    queue<pair<pii, int>> q;
    q.push({start, 0});
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        auto cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (graph[cur.first][cur.second] == 'D') {
            cout << cnt << endl;
            return ;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (visited[ny][nx]) continue;

            if (canMove(ny, nx) && waterGraph[ny][nx] > cnt + 1) {
                q.push({{ny, nx}, cnt + 1});
                visited[ny][nx] = 1;
            }
        }
    }
    cout << "KAKTUS" << endl;
}

void waterBFS() {
    while (!waterQ.empty()) {
        auto cur = waterQ.front();
        waterQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (isDomain(ny, nx) && graph[ny][nx] == '.') {
                if (waterGraph[ny][nx] > waterGraph[cur.first][cur.second] + 1) {
                    waterGraph[ny][nx] = waterGraph[cur.first][cur.second] + 1;
                    waterQ.push({ny, nx});
                }
            }
        }
    }
}

void solve() {
    waterBFS();
    bfs();
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
