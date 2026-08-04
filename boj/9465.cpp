#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 100001

void solve() {
    int input[2][SIZE], dp[3][SIZE];
    int N; cin >> N;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++)
            cin >> input[i][j];
    }
    for (int i = 1; i <= N; i++) {
        dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + input[0][i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + input[1][i];
    }
    cout << max(max(dp[0][N], dp[1][N]), dp[2][N]) << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
