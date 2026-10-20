#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int T, N, W, t;
vector<int> scores;

void init_input() {
    cin >> N >> W;
    scores.clear();
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        scores.push_back(a);
    }
}

void solve() {
    int ans, sum = 0;
    int l = 0, r = W - 1;
    for (int i = 0; i < W; i++) sum += scores[i];
    ans = sum;
    for (int i = 0, j = W; j < N; i++, j++) {
        sum = sum - scores[i] + scores[j];
        if (sum > ans) {
            l = i + 1;
            r = j;
            ans = sum;
        }
    }
    cout << '#' << t << ' ' << l << ' ' << r << ' ' << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (t = 1; t <= T; t++) {
        init_input();
        solve();
    }

    return 0;
}
