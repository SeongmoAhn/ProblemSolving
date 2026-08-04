#include <iostream>
#include <map>
using namespace std;
#define endl '\n'

void solve() {
    int N, M; cin >> N >> M;
    map<int, int> m;
    while (N--) {
        int n; cin >> n;
        m[n]++;
    }
    while (M--) {
        int n; cin >> n;
        cout << m[n] << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
