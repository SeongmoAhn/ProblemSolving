#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'

int n;
map<string, string, greater<>> m;

void initInput() {
    string name, status;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> status;
        m[name] = status;
    }
}

void solve() {
    map<string, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == "enter")
            cout << iter->first << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
