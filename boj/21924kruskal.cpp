#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define tiii tuple<int, int, int>
#define SIZE 100001

int n, m;
ll ans, sum;
vector<tiii> graph;
int parent[SIZE];

void initInput() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sum += c;
        graph.push_back({c, a, b});
    }
    sort(graph.begin(), graph.end());
}

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

bool unionParent(int v1, int v2) {
    int v = getParent(v1);
    int u = getParent(v2);

    if (v == u) return false;
    parent[u] = v;
    return true;
}

void kruskal() {
    for (int i = 0; i < graph.size(); i++) {
        if (unionParent(get<1>(graph[i]), get<2>(graph[i])))
            ans += get<0>(graph[i]);
    }
}

bool linkCheck() {
    int first = getParent(1);
    for (int i = 2; i <= n; i++) {
        if (first != getParent(i)) return false; 
    }
    return true;
}

void solve() {
    kruskal();
    if (linkCheck()) cout << sum - ans << endl;
    else cout << -1 << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
