#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 10001

int T, N;
int parent[SIZE];
bool visited[SIZE];

void initInput() {
    cin >> T;
}

void solve() {
    while (T--) {
        int u, v;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            visited[i] = 0;
            parent[i] = i;
        }

        for (int i = 0; i < N - 1; i++) {
            cin >> u >> v;
            parent[v] = u;
        }

        cin >> u >> v;
        visited[u] = 1;

        while (u != parent[u]) {
            u = parent[u];
            visited[u] = 1;
        }
        while (1) {
            if (visited[v]) {
                cout << v << endl;
                break;
            }
            v = parent[v];
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
