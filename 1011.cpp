#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long

void solve() {
    ll x, y; cin >> x >> y;
    ll ans, n = 0;
    while (n * n <= y - x) n++;
    n--;
    ans = 2 * n - 1;
    ans += (ll)ceil((double)(y - x - n * n) / (double)n);
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) solve();
}
