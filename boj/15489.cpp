#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define SIZE 31

int dp[SIZE][SIZE];
int R, C, W;
ll sum;

void initInput() {
    cin >> R >> C >> W;
}

void solve() {
    for (int i = 0; i < SIZE; i++) dp[i][0] = dp[i][i] = 1;
    for (int i = 2; i < SIZE; i++)
        for (int j = 1; j < i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    R--; C--;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < i + 1; j++) {
            sum += dp[i + R][j + C];
        }
    }
    cout << sum << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
