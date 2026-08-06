#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 101

int N, K, S;
vector<int> graph[SIZE];
int visited[SIZE][2];

void init_input() {
    cin >> N >> K >> S;
    while (K--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

void dfs(int node, int pre) {
    visited[node][pre] = 1;
    if (pre) cout << node << ' ';
    for (int i = graph[node].size() - 1; i >= 0; i--) {
        if (!visited[graph[node][i]][pre])
            dfs(graph[node][i], pre);
    }
    if (!pre) cout << node << ' ';
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    dfs(S, 1);
    cout << endl;
    dfs(S, 0);

    return 0;
}
