#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 10001

int N, ans, restart;
vector<pii> graph[SIZE];
bool visited[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
}

void dfs(int node, int len) {
    if (visited[node]) return;

    visited[node] = 1;
    if (ans < len) {
        ans = len;
        restart = node;
    }

    for (int i = 0; i < graph[node].size(); i++)
        dfs(graph[node][i].first, len + graph[node][i].second);
}

void solve() {
    dfs(1, 0);

    ans = 0;
    fill(visited, visited + SIZE, 0);
    dfs(restart, 0);

    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
