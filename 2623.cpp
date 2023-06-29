#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 1001

int n, m, cnt = 1;
int inDegree[SIZE];
vector<int> graph[SIZE];
vector<int> result;
queue<int> q;

void initInput() {
    cin >> n >> m;
    int size;
    for (int t = 0; t < m; t++) {
        vector<int> v;
        cin >> size;
        for (int i = 0; i < size; i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                graph[v[i]].push_back(v[j]);
                inDegree[v[j]]++;
            }
        }
    }
}

void topologySort() {
    for (int i = 1; i <= n; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            inDegree[next]--;

            if (!inDegree[next]) {
                q.push(next);
            }
        }
    }
}

void solve() {
    topologySort();
    if (result.size() != n) cout << 0 << endl;
    else {
        for (int i = 0; i < n; i++) {
            cout << result[i] << endl;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
