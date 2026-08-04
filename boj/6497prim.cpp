#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 200001

int V, E, ans, sum;
bool visited[SIZE];
priority_queue<pii> pq;
vector<pii> graph[SIZE];

void initInput() {
    sum = 0;
    ans = 0;
    fill(visited, visited + SIZE, false);
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        sum += c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void prim() {
    pq.push({0, 0});

    while (!pq.empty()) {
        int curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (visited[curNode]) continue;
        visited[curNode] = true;
        ans += curWeight;

        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextWeight = graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;
            pq.push({-nextWeight, nextNode});
        }
    }
}

void solve() {
    prim();
    cout << sum - ans << endl;
}

int main(void)
{
    PS_INPUT; 
    while (1) {
        cin >> V >> E;
        for (int i = 0; i < V; i++) graph[i].clear();
        if (!V && !E) break;
        initInput();
        solve();
    }
    
    return 0;
}
