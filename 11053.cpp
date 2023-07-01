#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define SIZE 1001

int n, ans;
int dp[SIZE];
int input[SIZE];

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (input[i] > input[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
