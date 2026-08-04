#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a, b, result = -1;
queue<pair<long long, int>> q;

void BFS() {
    q.push({a, 1});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == b) {
            result = cur.second;
            return ;
        }

        if (cur.first * 2 <= b) {
            q.push({cur.first * 2, cur.second + 1});
        }

        if (cur.first * 10 + 1 <= b) {
            q.push({cur.first * 10 + 1, cur.second + 1});
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
