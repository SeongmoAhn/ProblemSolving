#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T, cnt = 0; cin >> T;
    while (T--) {
        string str; cin >> str;
        vector<char> s;
        if (str.size() & 1) continue;
        s.push_back(str[0]);
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == s.back()) s.pop_back();
            else s.push_back(str[i]);
        }
        if (s.empty()) cnt++;
    }
    cout << cnt;
}
