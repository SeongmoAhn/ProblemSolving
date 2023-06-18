#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt;
vector<vector<int>> v(1001);
vector<bool> visited(1001);
queue<int> q;

void BFS(int x) {
    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        while (!v[cur].empty()) {
            int next = v[cur].back();
            v[cur].pop_back();
            q.push(next);
            visited[next] = true;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        v[input1].push_back(input2);
        v[input2].push_back(input1);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            BFS(i);
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
