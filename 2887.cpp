#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ll long long
#define SIZE 100001

int n;
int parent[SIZE];
vector<pii> X;
vector<pii> Y;
vector<pii> Z;
vector<tiii> planet;
ll ans;

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) parent[i] = i;
    int x, y, z;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < n - 1; i++) {
        planet.push_back({X[i + 1].first - X[i].first, X[i].second, X[i + 1].second});
        planet.push_back({Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second});
        planet.push_back({Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second});
    }
    sort(planet.begin(), planet.end());
}

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

bool unionParent(int v, int u) {
    v = getParent(v);
    u = getParent(u);
    if (u == v) return false;
    parent[u] = v;
    return true;
}

void kruskal() {
    for (int i = 0; i < planet.size(); i++) {
        int u = get<1>(planet[i]);
        int v = get<2>(planet[i]);
        int dist = get<0>(planet[i]);

        if (unionParent(u, v))
            ans += dist;
    }
}

void solve() {
    kruskal();
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
