#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 100001
#define MOD 1000000009

void solve() {
    int T; cin >> T;
    int dp[SIZE][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {1, 1, 1}, };
    vector<int> N;
    int M = -1;
    for (int i = 0; i < T; i++) {
        int input; cin >> input;
        N.push_back(input);
        M = max(M, input);
    }

    for (int i = 4; i <= M; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MOD;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % MOD;
    }

    for (int i = 0; i < T; i++) {
        int cur = N[i];
        cout << ((dp[cur][0] + dp[cur][1]) % MOD + dp[cur][2]) % MOD << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
