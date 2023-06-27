#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 1001

int n, m;
int inDegree[SIZE];
vector<int> graph[SIZE];
int result[SIZE];
queue<int> q;

void initInput() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b] += 1;
    }
}

void topologySort() {
    for (int i = 1; i <= n; i++) {
        if (!inDegree[i]) {
            q.push(i);
            result[i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            inDegree[next] -= 1;

            if (!inDegree[next]) {
                q.push(next);
                result[next] = result[cur] + 1;
            }
        }
    }
}

void solve() {
    topologySort();
    for (int i = 1; i <= n; i++) cout << result[i] << ' ';
    cout << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
