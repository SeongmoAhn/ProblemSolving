#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 100001
#define INF 1e9

int v;
vector<pair<int, int>> graph[SIZE];
bool visited[SIZE];
int maxDist;
int maxNode;
    
void initInput() {
    cin >> v;
    int vNum, v1, e;
    for (int i = 1; i <= v; i++) {
        cin >> vNum;
        while (1) {
            cin >> v1;
            if (v1 == -1) break;
            cin >> e;
            graph[vNum].push_back({v1, e});
            graph[v1].push_back({vNum, e});
        }
    }
}

void DFS(int node, int dist) {
    if (visited[node]) return;

    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }

    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        DFS(graph[node][i].first, graph[node][i].second + dist);
    }
}

void solve() {
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    int result = maxDist;
    maxDist = 0;
    DFS(maxNode, 0);
    result += maxDist;
    cout << maxDist << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
