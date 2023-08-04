#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 1001
#define MOD 10007

int N, ans;
int dp[SIZE][10];

void initInput() {
    cin >> N;
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
}

void solve() {
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    for (int i = 0; i < 10; i++)
        ans = (ans + dp[N][i]) % MOD;
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
