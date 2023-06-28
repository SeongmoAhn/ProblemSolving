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

int n;
ll ans;
vector<pii> graph[SIZE];
priority_queue<pii> pq;
bool visited[SIZE];

void initInput() {
    cin >> n;
    int e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ;j++) {
            cin >> e;
            if (i > j) {
                graph[i].push_back({j, e});
                graph[j].push_back({i, e});
            }
        }
    }
}

void prim() {
    pq.push({0, 2});

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
    cout << ans << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
