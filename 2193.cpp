#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define SIZE 91

int N;
ll dp[SIZE];

void initInput() {
    cin >> N;
    dp[1] = dp[2] = 1;
}

void solve() {
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[N] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
