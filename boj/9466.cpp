#include <iostream>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 100001

int testCase, n, cnt;
int graph[SIZE];
bool visited[SIZE];
bool check[SIZE];

void initInput() {
    cin >> n;
    fill(visited, visited + SIZE, 0);
    fill(check, check + SIZE, 0);
    cnt = 0;
    for (int i = 1; i <= n; i++) cin >> graph[i];
}

void DFS(int node) {
    visited[node] = true;

    int nextNode = graph[node];
    if (!visited[nextNode]) DFS(nextNode);
    else if (!check[nextNode]){
        for (int i = nextNode; i != node; i = graph[i]) cnt++;
        cnt++;
    }
    check[node] = true;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS(i);
    }
    cout << n - cnt << endl;
}

int main(void)
{
    PS_INPUT; 
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        initInput();
        solve();
    }

    return 0;
}
