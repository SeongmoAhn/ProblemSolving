#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define INF 0x7fffffff
#define SIZE 10001

int N;
int input[SIZE];
int dp[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    dp[1] = input[1];
    dp[2] = input[1] + input[2];
}

void solve() {
    for (int i = 3; i <= N; i++) {
        dp[i] = max(max(input[i] + input[i - 1] + dp[i - 3], dp[i - 2] + input[i]), dp[i - 1]);
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
