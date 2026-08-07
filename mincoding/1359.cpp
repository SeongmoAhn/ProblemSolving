#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

void solve() {
    string str; cin >> str;
    int alp[26] = {0};
    for (int i = 0; i < str.size(); i++) {
        alp[str[i] - 'A']++;
    }
    int max = -1;
    char ch = str[0];
    for (int i = 0; i < 26; i++) {
        if (alp[i] > max) {
            max = alp[i];
            ch = i + 'A';
        }
    }
    cout << ch;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
