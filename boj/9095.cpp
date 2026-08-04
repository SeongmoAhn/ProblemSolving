#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 11

int testCase;
int dp[SIZE];

void initInput() {
    cin >> testCase;
}

void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    while (testCase--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
