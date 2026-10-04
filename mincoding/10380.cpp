#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int C, B;
vector<int> foods;
int ans;

void init_input() {
    cin >> C >> B;
    for (int i = 0; i < B; i++) {
        int n; cin >> n;
        foods.push_back(n);
    }
}

void dfs(int idx, int sum) {
    ans = max(ans, sum);
    if (idx == B) return;

    // 현재 인덱스 값 안넣고 패스
    dfs(idx + 1, sum);

    // 현재 인덱스 값 넣고 계산
    if (sum + foods[idx] <= C)
        dfs(idx + 1, sum + foods[idx]);
}

void solve() {
    dfs(0, 0);
    cout << ans;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    solve();

    return 0;
}
