#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define SIZE 100001

int V, E, ans, maxLen = -1;
vector<tiii> graph;
int parent[SIZE];

void initInput() {
    cin >> V >> E;
    for (int i = 1; i <= V; i++) parent[i] = i;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
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
    for (int i = 0; i < E; i++) {
        if (unionParent(get<1>(graph[i]), get<2>(graph[i]))) {
            ans += get<0>(graph[i]);
            maxLen = get<0>(graph[i]);
        }
    }
}

void solve() {
    kruskal();
    cout << ans - maxLen << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
