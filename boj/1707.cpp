#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define endl '\n'
#define SIZE 20001
#define RED 1
#define BLUE 2

int testCase, v, e;
vector<int> vertex[SIZE];
int visited[SIZE];
queue<int> q;

void BFS(int node) {
    q.push(node); 
    int color = RED;
    visited[node] = color;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        color = (visited[cur] == RED) ? BLUE : RED;

        for (int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i];
            
            if (!visited[next]) {
                q.push(next);
                visited[next] = color;
            }
        }
    }
}

bool isBipartite() {
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < vertex[i].size(); j++) {
            int next = vertex[i][j];
            if (visited[i] == visited[next]) return 0;
        }
    }
    return 1;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        memset(vertex, 0, sizeof(vertex));
        memset(visited, 0, sizeof(visited));
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            vertex[v1].push_back(v2);
            vertex[v2].push_back(v1);
        }

        for (int i = 1; i <= v; i++) {
            if (!visited[i]) BFS(i);
        }

        isBipartite() ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
