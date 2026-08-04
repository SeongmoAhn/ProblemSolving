#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'

int n, m;
map<string, string> pw;

void initInput() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string site, password; cin >> site >> password;
        pw.insert({site, password});
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        string site; cin >> site;
        cout << pw[site] << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
