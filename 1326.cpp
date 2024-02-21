#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define SIZE 10001

int N, start, dest;
int graph[SIZE];
int ans[SIZE];
bool visited[SIZE];
queue<int> q;

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> graph[i];
    cin >> start >> dest;
}

void bfs() {
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == dest)
            return ;

        for (int i = cur + graph[cur]; i <= N; i += graph[cur]) {
            if (visited[i]) continue;
            ans[i] = ans[cur] + 1;
            q.push(i);
            visited[i] = 1;
        }
        for (int i = cur - graph[cur]; i > 0; i -= graph[cur]) {
            if (visited[i]) continue;
            ans[i] = ans[cur] + 1;
            q.push(i);
            visited[i] = 1;
        }
    }
}

void solve() {
    if (start == dest) {
        cout << "0";
        return ;
    }
    bfs();
    cout << (ans[dest] == 0 ? -1 : ans[dest]);
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
