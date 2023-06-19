#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> dp(1000001);
int n;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = 2100000000;
    }
    
    for (int i = 1; i <= n; i++) {
        if (i < n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i * 2 <= n) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if (i * 3 <= n) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    cout << dp[n] << endl;
    return 0;
}
