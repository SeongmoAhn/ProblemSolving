#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 10

int N, M;
int map[101];
queue<pii> q;
bool visited[101];

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }
}

void BFS() {
    q.push({1, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = cur.first + i;
            if (next == 100) {
                cout << cur.second + 1 << endl;
                return ;
            }
            else if (next < 100) {
                while (map[next] != 0) {
                    next = map[next];
                }
                if (!visited[next]) {
                    q.push({next, cur.second + 1});
                    visited[next] = true;
                }
            }
        }
    }
}

void solve() {
    BFS();
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
