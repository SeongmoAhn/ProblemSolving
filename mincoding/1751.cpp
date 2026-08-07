#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int alp[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        alp[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        char ch = i + 'A';
        if (alp[i]) cout << ch;
    }

    return 0;
}
