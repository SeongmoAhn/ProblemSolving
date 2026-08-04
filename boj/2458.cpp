#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define SIZE 501

int N, M;
int graph[SIZE][SIZE];
int cnt, ans;

void initInput() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = 1;
    }
}

void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void solve() {
    floyd();

    for (int i = 1; i <= N; i++) {
        cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] != INF || graph[j][i] != INF) cnt++;
        }
        if (cnt == N - 1) ans++;
    }
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
