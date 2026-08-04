#include <iostream>
#include <set>
using namespace std;
#define endl '\n'

int N, M;
set<int> s;

void init_input() {
    cin >> N >> M;
    while (M--) {
        int n; cin >> n;
        s.insert(n);
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        auto iter = s.upper_bound(n);
        if (iter == s.begin()) {
            cout << i - 1;
            return ;
        } else {
            s.erase(--iter);
        }
    }
    cout << N;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    solve();

    return 0;
}
