#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e10
#define pii pair<int, int>
#define ll long long
#define SIZE 100001

int n, m;
vector<pii> graph[SIZE];
bool sight[SIZE];
bool visited[SIZE];
ll distTable[SIZE];
priority_queue<pair<ll, int>> pq;

void initInput() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> sight[i];
    sight[n - 1] = 0;
    for (int i = 0; i < m; i++) {
        int v1, v2, e;
        cin >> v1 >> v2 >> e;
        if (!sight[v1] && !sight[v2]) {
            graph[v1].push_back({v2, e});
            graph[v2].push_back({v1, e});
        }
    }
}

void shortPath(int start) {
    fill(distTable, distTable + SIZE, INF);
    pq.push({0, start});
    distTable[start] = 0;

    while (!pq.empty()) {
        ll curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (distTable[curNode] < curDist) continue;

        for (int i = 0; i < graph[curNode].size(); i++) {
            ll cost = distTable[curNode] + graph[curNode][i].second;

            if (cost < distTable[graph[curNode][i].first]) {
                distTable[graph[curNode][i].first] = cost;
                pq.push({-cost, graph[curNode][i].first});
            }
        }
    }
}

void solve() {
    shortPath(0);
    if (distTable[n - 1] == INF) cout << -1 << endl;
    else cout << distTable[n - 1] << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
