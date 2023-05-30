#include <iostream>
// #include <string>
#include <algorithm>
#include <vector>
#include <queue>
// #include <deque>
using namespace std;
int cnt;
vector<int> graph[101];
bool visited[101];
queue<int> q;

void bfs(int node) {
    q.push(node);
    visited[node] = 1;
    cnt++;

    while (!q.empty()) {
        int frontOfQueue = q.front();
        q.pop();

        for (int i = 0; i < graph[frontOfQueue].size(); i++) {
            int cur = graph[frontOfQueue][i];
            if (!visited[cur]) {
                visited[cur] = 1;
                cnt++;
                q.push(cur);
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    pair<int, int> p;
    cin >> n;
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> p.first >> p.second;
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    bfs(1);

    cout << cnt - 1 << '\n';

    return 0;
}
