#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define SIZE 100

int N, M, ans;
vector<int> out[SIZE];
vector<int> in[SIZE];

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        in[a].push_back(b);
        out[b].push_back(a);
    }
}

int bfsOut(int node) {
    queue<int> q;
    bool visited[SIZE] = {0, };
    q.push(node);
    visited[node] = 1;
    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < out[cur].size(); i++) {
            int next = out[cur][i];
            if (visited[next]) continue;

            visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }

    return cnt;
}

int bfsIn(int node) {
    queue<int> q;
    bool visited[SIZE] = {0, };
    q.push(node);
    visited[node] = 1;
    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < in[cur].size(); i++) {
            int next = in[cur][i];
            if (visited[next]) continue;

            visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }

    return cnt;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (bfsOut(i) > (N - 1) / 2 || bfsIn(i) > (N - 1) / 2)
            ans++;
    }

    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
