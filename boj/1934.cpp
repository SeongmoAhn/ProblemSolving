#include <iostream>
using namespace std;
#define endl '\n'

int T;

void initInput() {
    cin >> T;
}

int divided(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    else {
        return divided(y, x % y);
    }
}

void solve() {
    while (T--) {
        int A, B; cin >> A >> B;

        if (A >= B) {
            cout << A * B / divided(A, B) << endl;
        }
        else {
            cout << A * B / divided(B, A) << endl;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
