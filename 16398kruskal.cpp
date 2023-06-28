#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define SIZE 1001

int n;
ll ans;
int graph[SIZE][SIZE];
vector<tiii> v;
int parent[SIZE];

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (i < j) v.push_back({graph[i][j], i, j});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) parent[i] = i;
}

int getParent(int x) {
    if (x == parent[x]) return x;

    return parent[x] = getParent(parent[x]);
}

bool unionParent(int v1, int v2) {
    int v = getParent(v1);
    int u = getParent(v2);

    if (v == u) return false;
    parent[v] = u;
    return true;
}

void kruskal() {
    for (int i = 0; i < v.size(); i++) {
        if (unionParent(get<1>(v[i]), get<2>(v[i])))
            ans += get<0>(v[i]);
    }
}

void solve() {
    kruskal();
    cout << ans << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
