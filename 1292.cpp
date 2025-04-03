#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 1002

int N, M;
int dp[SIZE];

void init_input()
{
    cin >> N >> M;
}

int solve()
{
    int cur = 1;
    int cnt = 0;
    int idx = 1;
    while (idx != (SIZE - 1)) {
        dp[idx] = dp[idx - 1] + cur;
        cnt++;
        if (cur == cnt) {
            cur++;
            cnt = 0;
        }

        idx++;
    }

    return dp[M] - dp[N - 1];
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    cout << solve() << endl;

    return 0;
}
