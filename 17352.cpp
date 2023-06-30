#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 300001

int n;
int parent[SIZE];

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int v1, int v2) {
    int v = getParent(v1);
    int u = getParent(v2);

    if (v == u) return;
    parent[u] = v;
    return;
}

bool isSame(int v1, int v2) {
    int u = getParent(v1);
    int v = getParent(v2);
    if (u == v) return true;
    return false;
}

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < (n - 2); i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }
}

void solve() {
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!isSame(i, j)) {
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
