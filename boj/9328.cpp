#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 111

int R, C, cnt;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
char graph[SIZE][SIZE];
bool visited[SIZE][SIZE];
int keys[26];

void initInput() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> graph[i][j];
    string key; cin >> key;
    for (int i = 0; i < key.size(); i++) {
        if (key[i] == '0') break;
        keys[key[i] - 'a']++;
    }
}

bool isInDomain(int y, int x) { return (y >= 0) && (y <= R + 1) && (x >= 0) && (x <= C + 1); }
bool canMove(int y, int x) { return ((isInDomain(y, x) && graph[y][x] != '*') ? 1 : 0); }

void bfs(int y, int x) {
    queue<pii> q;
    queue<pii> door[26];
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            char cur = graph[ny][nx];

            if (!canMove(ny, nx) || visited[ny][nx]) continue;
            visited[ny][nx] = 1;

            if ('A' <= cur && cur <= 'Z') {
                if (keys[cur - 'A']) q.push({ny, nx});
                else door[cur - 'A'].push({ny, nx});
            }
            else if ('a' <= cur && cur <= 'z') {
                q.push({ny, nx});
                if (!keys[cur - 'a']) {
                    keys[cur - 'a'] = 1;
                    while (!door[cur - 'a'].empty()) {
                        q.push(door[cur - 'a'].front());
                        door[cur - 'a'].pop();
                    }
                }
            }
            else {
                q.push({ny, nx});
                if (cur == '$') cnt++;
            }
        }
    }
}

void solve() {
    int T; cin >> T;
    while (T--) {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(keys, 0, sizeof(keys));
        cnt = 0;
        initInput();
        bfs(0, 0);
        cout << cnt << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
