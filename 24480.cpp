#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int check[100001];
int cnt;

void dfs(int node) {
    if (visited[node] == 1)
        return;
    visited[node] = 1;
    check[node] = ++cnt;
    for (int i = 0; i < graph[node].size(); i++) {
        dfs(graph[node][i]);
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

    dfs(r);

    for (i = 1; i <= n; i++) {
        cout << check[i] << '\n';
    }

    return 0;
}
