#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 501

int N, ans;
vector<pii> lines;
int dp[SIZE];

void initInput() {
    cin >> N;
    lines.push_back({0, 0});
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());
}

void solve() {
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (lines[i].second > lines[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << N - ans;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
