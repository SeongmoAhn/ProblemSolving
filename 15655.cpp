#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 9

int N, M;
vector<int> v, ans;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
}

void dfs(int idx, int size) {
    if (size == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    for (int i = idx; i < N; i++) {
        ans.push_back(v[i]);
        dfs(i + 1, size + 1);
        ans.pop_back();
    }
}

void solve() {
    sort(v.begin(), v.end());
    dfs(0, 0);
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
