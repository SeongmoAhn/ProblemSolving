#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N;
map<string, int> m;
int ans = -1;

void initInput() {
    cin >> N;
    while (N--) {
        string input; cin >> input;
        m[input]++;
    }
}

void solve() {
    for (auto iter = m.begin(); iter != m.end(); iter++)
        ans = max(ans, iter->second);
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (ans == iter->second) {
            cout << iter->first;
            return ;
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
