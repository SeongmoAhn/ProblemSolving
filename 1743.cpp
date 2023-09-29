#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 101

int N, M, K;
int graph[SIZE][SIZE];
vector<pii> point;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int ans = -1;

void initInput() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int y, x; cin >> y >> x;
        graph[y][x] = 1;
        point.push_back({y, x});
    }
}

bool isInArea(int y, int x) {
    return (y > 0) && (x > 0) && (y <= N) && (x <= M);
}

void solve() {
    queue<pii> q;

    for (int i = 0; i < point.size(); i++) {
        auto cur = point[i];
        if (!graph[cur.first][cur.second]) continue;

        q.push(cur);
        graph[cur.first][cur.second] = 0;

        int cnt = 0;
        while (!q.empty()) {
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            cnt++;

            for (int j = 0; j < 4; j++) {
                int nextY = curY + dy[j];
                int nextX = curX + dx[j];

                if (isInArea(nextY, nextX) && graph[nextY][nextX]) {
                    graph[nextY][nextX] = 0;
                    q.push({nextY, nextX});
                }
            }
        }
        ans = max(cnt, ans);
    }

    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
