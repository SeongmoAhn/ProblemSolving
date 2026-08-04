#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 100001

int n, m;
ll ans, total;
vector<pii> graph[SIZE];
bool visited[SIZE];
priority_queue<pii> pq;

void initInput() {
    cin >> n >> m;
    int a, b, c; 
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        total += c;
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
            int nextWeight = graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;

            pq.push({-nextWeight, nextNode});
        }
    }
}

bool linkCheck() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

void solve() {
    prim();
    if (linkCheck()) cout << total - ans << endl;
    else cout << -1 << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
