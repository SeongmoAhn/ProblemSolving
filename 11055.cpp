#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1001

int N;
int dp[SIZE], input[SIZE];

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (input[i] > input[j])
                dp[i] = max(dp[j] + input[i], dp[i]);
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
        dp[i] = input[i];
    }
    solve();
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}
