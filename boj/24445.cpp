#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int check[100001];
int cnt;
queue<int> q;

void bfs(int node) {
    q.push(node);
    visited[node] = 1;
    check[node] = ++cnt;
    while (!q.empty()) {
        int frontOfQueue = q.front();
        q.pop();

        for (int i = 0; i < graph[frontOfQueue].size(); i++) {
            int cur = graph[frontOfQueue][i];
            if (!visited[cur]) {
                visited[cur] = 1;
                q.push(cur);
                check[cur] = ++cnt;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, i, r;
    cin >> n >> m >> r;
    pair<int, int> point;
    for (i = 1; i <= m; i++) {
        cin >> point.first >> point.second;
        graph[point.first].push_back(point.second);
        graph[point.second].push_back(point.first);
    }
    for (i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    bfs(r);

    for (i = 1; i <= n; i++) {
        cout << check[i] << '\n';
    }

    return 0;
}
