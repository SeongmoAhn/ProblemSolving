#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define INF 1e9
#define SIZE 401

int V, E;
int graph[SIZE][SIZE];
int ans = INF;

void initInput() {
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1][v2] = min(graph[v1][v2], w);
    }
}

void floyd() {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void solve() {
    floyd();

    for (int i = 1; i <= V; i++) {
        ans = min(ans, graph[i][i]);
    }

    cout << ((ans == INF) ? -1 : ans);
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
