#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long

ll N;
ll ans;

void initInput() {
    cin >> N;
    ans = N;
}

void makePrime() {

}

void solve() {
    for (ll i = 2; i * i <= N; i++) {
#ifdef DEBUG
    cout << "current i : " << i << endl;
#endif
        if (N % i == 0) {
#ifdef DEBUG
    cout << "current number : " << i << endl;
#endif
            ans -= ans / i;
            while (N % i == 0) N /= i;
        }
    }
    if (N > 1) ans -= ans / N;
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
