#include <iostream>
#include <map>
using namespace std;
#define endl '\n'

void solve() {
    int N, M; cin >> N >> M;
    map<int, int> m;
    while (N--) {
        int n; cin >> n;
        m[n] = 1;
    }
    int cnt = 0;
    while (M--) {
        int n; cin >> n;
        if (m.count(-n)) {
            cnt++;
            m.erase(-n);
        }
    }
    cout << cnt;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
