#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    string input, str;
    int ans = 0;
    getline(cin, input);
    getline(cin, str);
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != str[0]) continue;
        bool flag = 1;
        for (int j = 1; j < str.size(); j++) {
            if (input[i + j] != str[j]) { flag = 0; break; }
        }
        if (flag) {
            ans++;
            i += str.size();
            i--;
        }
    }
    cout << ans;
}
