#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
int visitedBFS[1001];
int visitedDFS[1001];
int cntBFS, cntDFS;
int resultBFS[1001], resultDFS[1001];
queue<int> q;

void BFS(int node) {
    q.push(node);
    cout << node << " ";
    visitedBFS[node] = 1;
    resultBFS[node] = ++cntBFS;

    while (!q.empty()) {
        int frontOfQueue = q.front();
        q.pop();

        for (int i = 0; i < graph[frontOfQueue].size(); i++) {
            int cur = graph[frontOfQueue][i];
            if (!visitedBFS[cur]) {
                q.push(cur);
                cout << cur << " ";
                visitedBFS[cur] = 1;
                resultBFS[cur] = ++cntBFS;
            }
        }
    }
}

void DFS(int node) {
    if (visitedDFS[node]) {
        return;
    }
    cout << node << " ";
    visitedDFS[node] = 1;
    resultDFS[node] = ++cntDFS;
    for (int i = 0; i < graph[node].size(); i++) {
        DFS(graph[node][i]);
    }
}

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input, n, m, i, r;
    pair<int, int> p;
    cin >> n >> m >> r;
    for (i = 0; i < m; i++) {
        cin >> p.first >> p.second;
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    for (i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(r);
    cout << '\n';
    BFS(r);
    cout << '\n';

    return 0;
}
