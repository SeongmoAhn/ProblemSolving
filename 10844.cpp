#include <iostream>
using namespace std;
#define endl '\n'
#define INF 1e9
#define MOD 1000000000

int N, ans;
int dp[101][10];

void initInput() {
    cin >> N;
}

void solve() {
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (!j) {
                dp[i][j] = dp[i - 1][1] % MOD;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % MOD;
            }
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }

    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
