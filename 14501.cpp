#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define SIZE 16

int N;
int tm[SIZE], price[SIZE], dp[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t, p; cin >> t >> p;
        tm[i] = t;
        price[i] = p;
        dp[i] = -1;
    }
}

int dfs(int day) {
    if (day > N + 1) return -INF;
    else if (day == N + 1) return 0;

    int ret = dp[day];
    if (ret != -1) return ret;

    ret = max(dfs(day + 1), dfs(day + tm[day]) + price[day]);
    return ret;
}

void solve() {
    cout << dfs(1) << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
