#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define INT_INF 0x7fffffff
#define SIZE 1001

int N, M;
string graph[SIZE];
int fireMap[SIZE][SIZE];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
pii start;
queue<pii> q;
queue<pair<pii, int>> ansq;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 'J') {
                start = {i, j};
                graph[i][j] = '.';
                fireMap[i][j] = INT_INF;
            }
            else if (graph[i][j] == 'F') {
                q.push({i, j});
                fireMap[i][j] = 0;
            }
            else {
                fireMap[i][j] = INT_INF;
            }
        }
    }
}

bool isInDomain(int y, int x) {
    return ((y >= 0) && (x >= 0) && (y < N) && (x < M));
}

bool canMove(int y, int x) {
    return (isInDomain(y, x) && graph[y][x] == '.');
}

bool isEdge(int y, int x) {
    return (y == 0 || x == 0 || y == N - 1 || x == M - 1);
}

void getFireMap() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (canMove(ny, nx)) {
                if (fireMap[y][x] + 1 < fireMap[ny][nx]) {
                    q.push({ny, nx});
                    fireMap[ny][nx] = fireMap[y][x] + 1;
                }
            }
        }
    }
}

void BFS() {
    ansq.push({start, 0});
    graph[start.first][start.second] = '#';

    while (!ansq.empty()) {
        int y = ansq.front().first.first;
        int x = ansq.front().first.second;
        int cnt = ansq.front().second;
        ansq.pop();

        if (isEdge(y, x)) {
            cout << cnt + 1 << endl;
            return ;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int ncnt = cnt + 1;

            if (canMove(ny, nx) && fireMap[ny][nx] > ncnt) {
                ansq.push({{ny, nx}, ncnt});
                graph[ny][nx] = '#';
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}

void solve() {
    getFireMap();
    BFS();
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
