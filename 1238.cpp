#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 1001
#define INF 1e9

int n, m, point;
vector<pair<int, int>> graph[SIZE];
int distTable[SIZE];
int distTable1[SIZE];
priority_queue<pair<int, int>> pq;

void initInput() {
    cin >> n >> m >> point;
    for (int i = 0; i < m; i++) {
        int v1, v2, t;
        cin >> v1 >> v2 >> t;
        graph[v1].push_back({v2, t});
    }
    fill(distTable, distTable + SIZE, INF);
}

int shortPath1(int x) {
    fill(distTable1, distTable1 + SIZE, INF);
    distTable1[x] = 0;
    pq.push({0, x});

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[curNode].size(); i++) {
            int cost = distTable1[curNode] + graph[curNode][i].second;

            if (cost < distTable1[graph[curNode][i].first]) {
                distTable1[graph[curNode][i].first] = cost;
                pq.push({-cost, graph[curNode][i].first});
            }
        }
    }
    return distTable1[point];
}

void shortPath(int x) {
    distTable[x] = 0;
    pq.push({0, x});

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
    shortPath(point);
    int result = -1;
    for (int i = 1; i <= n; i++) {
        if (distTable[i] != INF) {
            result = max(result, shortPath1(i) + distTable[i]);
        }
    }
    cout << result << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
