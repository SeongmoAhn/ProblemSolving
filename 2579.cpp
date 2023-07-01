#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 301

int n;
int stair[SIZE];
int dp[SIZE];

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }
}

void solve() {
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
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
