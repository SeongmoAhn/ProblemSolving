#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'

map<string, double> m;
int cnt;

void initInput() {
    string input;

    while (getline(cin, input)) {
        cnt++;
        m[input]++;
    }
}

void solve() {
    cout << fixed;
    cout.precision(4);
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << ' ' << (it->second) / cnt * 100 << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
