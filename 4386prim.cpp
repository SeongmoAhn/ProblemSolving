#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
bool visited[SIZE];
priority_queue<pair<double, int>> pq;

double getLen(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void initInput() {
    cin >> n;
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

void prim() {
    pq.push({0.0, 0});

    while (!pq.empty()) {
        double curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (visited[curNode]) continue;
        visited[curNode] = true;
        ans += curWeight;
        
        for (int i = 0; i < n; i++) {
            if (curNode == i) continue;

            double nextWeight = getLen(stars[curNode].first, stars[curNode].second, stars[i].first, stars[i].second);
            pq.push({-nextWeight, i});
        }
    }
}

void solve() {
    prim();
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
