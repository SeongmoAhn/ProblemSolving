#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 100001

int main(void) {
    int N; cin >> N;
    int dp[SIZE] = {0, };
    for (int i = 1; i <= N; i++) dp[i] = i;
    for (int i = 1; i * i <= N; i++) {
        int cur = i * i;
        for (int j = 1; j <= N; j++) {
            if (j - cur < 0) continue;
            dp[j] = min(dp[j], dp[j - cur] + 1);
        }
    }

    cout << dp[N] << '\n';
}
