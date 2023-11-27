#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 21

int N, ans = 1e9;
int map[SIZE][SIZE];
bool visited[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    }
}

void dfs(int idx, int cnt) {
    if (cnt == N / 2) {
        int start = 0, link = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visited[i] && visited[j]) start += map[i][j];
                if (!(visited[i] || visited[j])) link += map[i][j];
            }
        }
        ans = min(ans, start > link ? start - link : link - start);

        return ;
    }

    for (int i = idx; i < N; i++) {
        visited[i] = 1;
        dfs(i + 1, cnt + 1);
        visited[i] = 0;
    }
}

void solve() {
    dfs(1, 0);
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
