#include <iostream>
#include <string>
#include <set>
using namespace std;
#define endl '\n'

int n;
char game;
set<string> s;

void initInput() {
    cin >> n >> game;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        s.insert(name);
    }
}

void solve() {
    if (game == 'Y')
        cout << s.size() << endl;
    else if (game == 'F')
        cout << s.size() / 2 << endl;
    else cout << s.size() / 3 << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
