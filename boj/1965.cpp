#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 1001

int N, input[SIZE], dp[SIZE];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> input[i];
    for (int i = 1; i < SIZE; i++) dp[i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i; j > 0; j--) {
            if (input[i] > input[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i < SIZE; i++) ans = max(ans, dp[i]);
    cout << ans;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();
}
