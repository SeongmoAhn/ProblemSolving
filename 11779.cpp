#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 1001

int V, E, start, target;
vector<pii> graph[SIZE];
int distTable[SIZE];
priority_queue<pii> pq;
int course[SIZE];

void initInput() {
    cin >> V >> E;
    fill(distTable, distTable + SIZE, INF);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> start >> target;
}

void shortPath(int start) {
    distTable[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDist > distTable[curNode]) continue;

        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextNode = graph[curNode][i].first;
            int nextDist = graph[curNode][i].second;

            int cost = curDist + nextDist;

            if (cost < distTable[nextNode]) {
                distTable[nextNode] = cost;
                pq.push({-cost, nextNode});
                course[nextNode] = curNode;
            }
        }
    }
}

void solve() {
    shortPath(start);
    cout << distTable[target] << endl;
    vector<int> v;
    int cur = course[target];
    v.push_back(target);
    while (cur) {
        v.push_back(cur);
        cur = course[cur];
    }
    cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
    cout << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
