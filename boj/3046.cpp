#include <iostream>
using namespace std;
#define endl '\n'

int r, s;

void initInput() {
    cin >> r >> s;
}

void solve() {
    int ans = s * 2 - r;
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
