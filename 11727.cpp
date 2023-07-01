#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 1001

int n;
int dp[SIZE];

void initInput() {
    cin >> n;
}

void solve() {
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
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
