#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph(100001);
vector<int> visited(100001);

void DFS(int node, int prev) {
    if (visited[node]) return;

    visited[node] = prev;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        DFS(next, node);
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    int n1, n2;
    for (int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    DFS(1, 1);

    for (int i = 2; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
