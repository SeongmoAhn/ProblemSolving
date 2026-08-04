#include <iostream>
#include <map>
#include <string>
using namespace std;
#define endl '\n'

void solve() {
    int N; cin >> N;
    map<string, int> m;
    while (N--) {
        string a, b; cin >> a >> b;
        m[a]++;
        m[b]--;
    }

    int a = 0, b = 0, c = 0;
    for (auto &iter : m) {
        if (iter.second > 0) a++;
        else if (iter.second < 0) b++;
        else c++;
    }
    cout << a << ' ' << b << ' ' << c;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
