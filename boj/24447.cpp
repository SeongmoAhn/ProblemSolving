#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 100001

int n, m, start;
vector<int> graph[SIZE];
int depth[SIZE];
ll seq[SIZE];
queue<int> q;

void initInput() {
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());
}

void BFS(int start) {
    q.push(start);
    depth[start] = 0;
    seq[start] = 1;
    int cnt = 1;

    while (!q.empty()) {
        int curNode = q.front();
        int curDepth = depth[curNode];
        q.pop();

        for (int i = 0; i < graph[curNode].size(); i++) {
            if (depth[graph[curNode][i]] == -1) {
                q.push(graph[curNode][i]);
                depth[graph[curNode][i]] = curDepth + 1;
                seq[graph[curNode][i]] = ++cnt;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) depth[i] = -1;
    BFS(start);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += depth[i] * seq[i];
    }
    cout << sum << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
