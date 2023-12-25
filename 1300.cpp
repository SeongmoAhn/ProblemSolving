#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long

ll N, K;
ll ans; 

ll cnt(ll mid) {
    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        ret += min(N, (ll)mid / i);
        if (i > mid) break;
    }
    return ret;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    ll low = 1, high = N * N;
    while (low <= high) {
        ll mid = (low + high) / 2;

        if (cnt(mid) < K)
            low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << ans << endl;
}
