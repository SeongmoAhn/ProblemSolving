#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 1000001

int N, M;
int parent[SIZE];

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int v1, int v2) {
    int v = getParent(v1);
    int u = getParent(v2);
    if (u == v) return;
    parent[u] = v;
    return;
}

void initInput() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;
    int print, a, b;
    for (int i = 0; i < M; i++) {
        cin >> print >> a >> b;
        if (print) {
            if (getParent(a) == getParent(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            unionParent(a, b);
        }
    }
}

void solve() {
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
