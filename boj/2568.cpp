#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 100001

int N;
vector<pii> lines;
vector<int> ans;
int dp[SIZE], memo[SIZE];
int len;

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());
}

void solve() {
    dp[len++] = lines[0].second;
    for (int i = 1; i < N; i++) {
        if (lines[i].second > dp[len - 1]) {
            dp[len++] = lines[i].second;
            memo[i] = len - 1;
        }
        else {
            int *iter = lower_bound(dp, dp + len, lines[i].second);
            *iter = lines[i].second;
            memo[i] = iter - dp;
        }
    }
    cout << N - len << endl;

    int cnt = len - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (cnt == memo[i]) {
            ans.push_back(i);
            cnt--;
        }
    }

    int t = ans.back(); ans.pop_back();
    for (int i = 0; i < N; i++) {
        if (t == i) {
            if (ans.empty()) continue;
            t = ans.back(); ans.pop_back();
        }
        else
            cout << lines[i].first << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
