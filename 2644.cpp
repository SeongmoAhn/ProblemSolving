#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, p1, p2;
vector<vector<int>> v(101);
vector<int> visited(101);
queue<int> q;

void BFS(int x) {
    q.push(x);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        while (!v[cur].empty()) {
            int next = v[cur].back();
            v[cur].pop_back();

            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> p1 >> p2;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        v[input1].push_back(input2);
        v[input2].push_back(input1);
    }

    BFS(p1);

    if (!visited[p2]) cout << -1 << '\n';
    else cout << visited[p2] << '\n';

    return 0;
}
