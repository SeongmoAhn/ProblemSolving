#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, M;
vector<int> input;
vector<int> ans;

void solve(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << endl;
        return ;
    }

    for (int i = 0; i < N; i++) {
        ans.push_back(input[i]);
        solve(i, cnt + 1);
        ans.pop_back();
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    solve(0, 0);

    return 0;
}
