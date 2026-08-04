#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 101

int N, target;
int dp[10001];
int coins[SIZE];

void initInput() {
    cin >> N >> target;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    dp[0] = 1;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = coins[i]; j <= target; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[target] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
