#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'

int T, n;

void initInput() {
    cin >> T;
}

void solve() {
    while (T--) {
        map<string, int> wear;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            wear[b]++;
        }

        int ans = 1;
        map<string, int>::iterator iter;
        for (iter = wear.begin(); iter != wear.end(); iter++) {
            ans *= (iter->second + 1);
        }
        cout << ans - 1 << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
