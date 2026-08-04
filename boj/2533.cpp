#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 1000001
#define EARLY 0
#define NORMAL 1

int N;
vector<int> tree[SIZE];
int dp[SIZE][2];
bool visited[SIZE];

void initInput() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

void solve(int node) {
    visited[node] = 1;
    dp[node][EARLY] = 1;

    for (int i = 0; i < tree[node].size(); i++) {
        int adjNode = tree[node][i];
        if (visited[adjNode]) continue;

        solve(adjNode);
        dp[node][NORMAL] += dp[adjNode][EARLY];
        dp[node][EARLY] += min(dp[adjNode][NORMAL], dp[adjNode][EARLY]);
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve(1);
    cout << min(dp[1][NORMAL], dp[1][EARLY]) << endl;

    return 0;
}
