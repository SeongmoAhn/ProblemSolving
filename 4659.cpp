#include <iostream>
#include <string>
using namespace std;

bool isMo(char c) { return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'); }

void solve() {
    string str;

    while (1) {
        cin >> str; if (str == "end") break;

        cout << "<" + str + "> is ";

        int flag = 1;
        for (int i = 0; i < str.size(); i++) {
            if (isMo(str[i])) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "not acceptable.\n";
            continue;
        }

        for (int i = 0; i < str.size() - 1; i++) {
            flag = 0;
            if (str[i] == str[i + 1] && str[i] != 'e' && str[i] != 'o') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "not acceptable.\n";
            continue;
        }

        for (int i = 0; i < str.size(); i++) {
            flag = 0;
            if (isMo(str[i])) {
                if (i + 1 < str.size() && isMo(str[i + 1])) flag++;
                if (i + 2 < str.size() && isMo(str[i + 2])) flag++;
                if (flag == 2) break;
            }
            else {
                if (i + 1 < str.size() && !isMo(str[i + 1])) flag++;
                if (i + 2 < str.size() && !isMo(str[i + 2])) flag++;
                if (flag == 2) break;
            }
        }
        if (flag > 1) {
            cout << "not acceptable.\n";
            continue;
        }

        cout << "acceptable.\n";
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();
}
