#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int a, b, result = -1;
queue<pair<long long, int>> q;
vector<bool> visited(MAX);

void BFS() {
    q.push({a, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == b) {
            result = cur.second;
            return ;
        }

        if (cur.first + 1 >= 0 && cur.first + 1 < MAX) {
            if (!visited[cur.first + 1]) {
                q.push({cur.first + 1, cur.second + 1});
                visited[cur.first + 1] = 1;
            }
        }

        if (cur.first - 1 >= 0 && cur.first - 1 < MAX) {
            if (!visited[cur.first - 1]) {
                q.push({cur.first - 1, cur.second + 1});
                visited[cur.first - 1] = 1;
            }
        }

        if (cur.first * 2 >= 0 && cur.first * 2 < MAX) {
            if (!visited[cur.first * 2]) {
                q.push({cur.first * 2, cur.second + 1});
                visited[cur.first * 2] = 1;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a >> b;
    BFS();
    cout << result << '\n';

    return 0;
}
