#include <iostream>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int E, S, M; cin >> E >> S >> M;
    int e = 1, s = 1, m = 1, ans = 1;

    do {
        if (e == E && s == S && m == M) {
            cout << ans << endl;
            return 0;
        }
        e++; s++; m++;
        if (e == 16) e = 1;
        if (s == 29) s = 1;
        if (m == 20) m = 1;
    } while (ans++);
}
