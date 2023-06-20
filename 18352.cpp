#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 300001
#define INF 1e9

int v, e, dist, start;
vector<pair<int, int>> graph[SIZE];
int distTable[SIZE];
priority_queue<pair<int, int>> pq;
vector<int> result;

void initInput() {
    cin >> v >> e >> dist >> start;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back({v2, 1});
    }
}

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

void solve() {
    shortPath();
    for (int i = 1; i <= v; i++) {
        if (distTable[i] == dist) {
            result.push_back(i);
        }
    }

    if (!result.empty()) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] <<endl;
        }
    }
    else cout << -1 << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
