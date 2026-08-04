#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 10001
#define INF 1e9

int testCase, n, d, start;
vector<pair<int, int>> graph[SIZE];
int distTable[SIZE];
priority_queue<pair<int, int>> pq;

void initInput() {
    cin >> testCase;
}

void shortPath() {
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
    for (int t = 0; t < testCase; t++) {
        for (int i = 0; i < SIZE; i++)  graph[i].clear();
        fill(distTable, distTable + SIZE, INF);
        cin >> n >> d >> start;

        for (int i = 0; i < d; i++) {
            int v1, v2, addictTime;
            cin >> v1 >> v2 >> addictTime;
            graph[v2].push_back({v1, addictTime});
        }

        shortPath();

        int result = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (distTable[i] != INF) {
                cnt++;
                result = max(result, distTable[i]);
            }
        }
        cout << cnt << ' ' << result << endl;
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
