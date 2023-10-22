#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 1025

int N, M;
int dp[SIZE][SIZE];

void initInput() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int input; cin >> input;
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] + input - dp[i - 1][j - 1]);
        }
    }
}

void solve() {
    while (M--) {
        int ans = 0;
        int x1, x2, y1, y2; cin >> y1 >> x1 >> y2 >> x2;
        ans += dp[y2][x2];
        ans -= (dp[y1 - 1][x2] + dp[y2][x1 - 1]);
        ans += dp[y1 - 1][x1 - 1];
        cout << ans << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
