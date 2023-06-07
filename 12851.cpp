#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int a, b, result, cnt;
queue<pair<int, int>> q;
bool visited[MAX];

void BFS() {
    q.push({a, 0});
    visited[a] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        visited[cur.first] = 1;

        if (result && result == cur.second && cur.first == b)
            cnt++;

        if (cur.first == b && !result) {
            result = cur.second;
            cnt++;
        }


        if (cur.first + 1 < MAX && !visited[cur.first + 1]) {
            q.push({cur.first + 1, cur.second + 1});
        }
        if (cur.first - 1 >= 0 && !visited[cur.first - 1]) {
            q.push({cur.first - 1, cur.second + 1});
        }

        if (cur.first * 2 < MAX && !visited[cur.first * 2]) {
            q.push({cur.first * 2, cur.second + 1});
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a >> b;
    BFS();
    cout << result << '\n' << cnt << '\n';

    return 0;
}
