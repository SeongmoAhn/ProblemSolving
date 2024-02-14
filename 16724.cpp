#include <iostream>
#include <map>
using namespace std;
#define endl '\n'
#define SIZE 1000

int N, M;
char graph[SIZE][SIZE];
map<char, pair<int, int>> m;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];

    m.insert({'U', {-1, 0}});
    m.insert({'D', {1, 0}});
    m.insert({'L', {0, -1}});
    m.insert({'R', {0, 1}});
}

bool dfs(int y, int x) {
    if (graph[y][x] == 0) return 1;
    else if (graph[y][x] == 1) return 0;

    char cur = graph[y][x];
    graph[y][x] = 0;
    bool ret = dfs(y + m[cur].first, x + m[cur].second);
    graph[y][x] = 1;

    return ret;
}

void solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dfs(i, j))
                ans++;
        }
    }
    cout << ans;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
