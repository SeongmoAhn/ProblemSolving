#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1001

int N, M;
int dp[SIZE][SIZE];
int graph[SIZE][SIZE];
int dy[] = {-1, 0, -1};
int dx[] = {0, -1, -1};

void initInput() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> graph[i][j];
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 3; k++) {
                int prevY = i + dy[k];
                int prevX = j + dx[k];
                dp[i][j] = max(dp[i][j], graph[i][j] + dp[prevY][prevX]);
            }
        }
    }
    cout << dp[N][M] << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
