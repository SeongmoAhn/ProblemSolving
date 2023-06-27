#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 32001

int n, m;
vector<int> graph[SIZE];
int inDegree[SIZE];
queue<int> q;

void initInput() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }
}

void topologySort() {
    for (int i = 1; i <= n; i++)
        if (!inDegree[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            inDegree[next]--;

            if (!inDegree[next]) q.push(next);
        }
    }
    cout << endl;
}

void solve() {
    topologySort();
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
