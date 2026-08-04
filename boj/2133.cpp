#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 31

int N;
int dp[SIZE] = {0, 0, 3};

void initInput() {
    cin >> N;
}

void solve() {
    for (int i = 4; i <= N; i++) {
        if (i & 1) continue;

        dp[i] = dp[i - 2] * 3;

        int sum = 1;
        for (int j = 1; j <= (i / 2 - 2); j++)
            sum += dp[2 * j];
        sum *= 2;
        dp[i] += sum;
    }

    cout << dp[N] << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
