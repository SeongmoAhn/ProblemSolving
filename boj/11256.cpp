#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

void solve() {
    int a, b, ans = 0; cin >> a >> b;
    vector<int> box;
    for (int i = 0; i < b; i++) {
        int c, d; cin >> c >> d;
        box.push_back(c * d);
    }
    sort(box.begin(), box.end(), greater<>());
    for (; a > 0; ans++) a -= box[ans];
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) solve();
}
