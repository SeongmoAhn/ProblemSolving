#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 100001

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;
    int dp[SIZE] = {0, }, arr[SIZE] = {0, };
    int dp2[SIZE] = {0, };
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        if (arr[i] >= arr[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] <= arr[i - 1]) dp2[i] = dp2[i - 1] + 1;
        else dp2[i] = 1;
    }

    int ans = dp[1];
    for (int i = 2; i <= N; i++)
        ans = max(ans, max(dp[i], dp2[i]));
    cout << ans << '\n';
}
