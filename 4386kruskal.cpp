#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 101

int n;
double ans;
vector<pair<double, double>> stars;
vector<pair<double, pii>> graph;
int parent[SIZE];

double getLen(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) parent[i] = i;
    double a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        stars.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double len = getLen(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
            graph.push_back({len, {i, j}});
        }
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
    parent[v] = u;
    return true;
}

void kruskal() {
    for (int i = 0; i < graph.size(); i++) {
        if (unionParent(graph[i].second.first, graph[i].second.second)) {
            ans += graph[i].first;
        }
    }
}

void solve() {
    kruskal();
    cout.precision(3);
    cout << ans << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
