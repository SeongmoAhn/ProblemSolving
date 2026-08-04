#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define SIZE 20001

int n, m, start;
vector<pair<int, int>> graph[SIZE];
int distTable[SIZE];
priority_queue<pair<int, int>> pq;

void shortPath() {
    fill(distTable, distTable + SIZE, INF);
    distTable[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[curNode].size(); i++) {
            int cost = distTable[curNode] + graph[curNode][i].second;

            if (cost < distTable[graph[curNode][i].first]) {
                distTable[graph[curNode][i].first] = cost;
                pq.push({-cost, graph[curNode][i].first});
            }
        }
    }

}

int main() {
    PS_INPUT;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int v1, v2, e;
        cin >> v1 >> v2 >> e;
        graph[v1].push_back({v2, e});
    }

    shortPath();

    for (int i = 1; i <= n; i++) {
        if (distTable[i] == INF) cout << "INF" << endl;
        else cout << distTable[i] << endl;
    }
    
    return 0;
}
