#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define SIZE 1001

int n, m, start, dest;
vector<pair<int, int>> graph[SIZE];
int distTable[SIZE];
priority_queue<pair<int, int>> pq;

void dijkstra() {
    pq.push({0, start});
    distTable[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (distTable[cur] < dist) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int cost = dist + graph[cur][i].second;

            if (cost < distTable[graph[cur][i].first]) {
                distTable[graph[cur][i].first] = cost;
                pq.push({-cost, graph[cur][i].first});
            }
        }
    }
}

int main(void)
{
    PS_INPUT; 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2, e;
        cin >> v1 >> v2 >> e;
        graph[v1].push_back({v2, e});
    }
    cin >> start >> dest;

    fill(distTable, distTable + SIZE, INF);

    dijkstra();

    cout << distTable[dest] << endl;

    return 0;
}
