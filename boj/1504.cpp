#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 801
#define INF 1e9

int n, e, start = 1, a, b;
vector<pair<int, int>> graph[SIZE];
int distTable[SIZE];
priority_queue<pair<int, int>> pq;

void initInput() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }
    cin >> a >> b;
}

int shortPath(int startNode, int destNode) {
    fill(distTable, distTable + SIZE, INF);
    distTable[startNode] = 0;
    pq.push({0, startNode});

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
    return distTable[destNode];
}

int solve() {
    int distA = shortPath(start, a);
    int distB = shortPath(start, b);
    int distAB = shortPath(a, b);
    if (distAB == INF) return -1;
    int distAN = shortPath(a, n);
    if (distB == INF && distAN == INF) return -1;
    int distBN = shortPath(b, n);
    if (distA == INF && distBN == INF) return -1;

    return min(distA + distAB + distBN, distB + distAB + distAN);
}

int main(void)
{
    PS_INPUT; 
    initInput();
    int result = solve();
    if (result == -1 || result >= INF) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
