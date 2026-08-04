#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 50001

int n;
int dp[SIZE];

void initInput() {
    cin >> n;
    dp[1] = 1;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
