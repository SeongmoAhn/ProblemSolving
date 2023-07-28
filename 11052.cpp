#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1001

int N;
int input[SIZE];
int dp[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
        dp[i] = input[i];
    }
}

void solve() {
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }
    cout << dp[N] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
