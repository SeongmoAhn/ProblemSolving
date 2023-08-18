#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long

void initInput() {
}

void solve() {
    while (1) {
        int N; cin >> N; if (!N) break;
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = N;

        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                ans -= ans / i;
                while (N % i == 0) N /= i;
            }
        }
        if (N > 1) ans -= ans / N;
        cout << ans << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
