#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 1010
#define MOD 10007

int N, K;
int dp[SIZE][SIZE];

void initInput() {
    cin >> N >> K;
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j || j == 1)
                dp[i][j] = 1;
        }
    }
}

void solve() {
    for (int i = 3; i < SIZE; i++) {
        for (int j = 2; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[N + 1][K + 1];
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
