#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long

int input;
int cnt;

void initInput() {
    cin >> input;
}

void solve() {
    if (input == 1) {
        cout << 0 << endl;
        return;
    }
    for (int N = 2; N <= input; N++) {
        int cur = N;
        int ans = cur;

        for (int i = 2; i * i <= cur; i++) {
            if (cur % i == 0) {
                ans -= ans / i;
                while (cur % i == 0) cur /= i;
            }
        }
        if (cur > 1) ans -= ans / cur;
        cnt += ans;
    }
    cout << cnt << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
