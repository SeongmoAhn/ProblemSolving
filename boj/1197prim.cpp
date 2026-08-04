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
#define SIZE 10001

int V, E;
bool visited[SIZE];
ll ans;
vector<pii> graph[SIZE];
priority_queue<pii> pq;

void initInput() {
    cin >> V >> E;

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void prim() {
    pq.push({0, 1});

    while (!pq.empty()) {
        int curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (visited[curNode]) continue;

        visited[curNode] = true;
        ans += curWeight;

        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextNode = graph[curNode][i].first;
            int nextWeight = graph[curNode][i].second;

            pq.push({-nextWeight, nextNode});
        }
    }
}

void solve() {
    prim();
    cout << ans << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
