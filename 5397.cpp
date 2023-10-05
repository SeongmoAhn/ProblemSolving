#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

int N;

void initInput() {
    cin  >> N;
}

void solve() {
    while (N--) {
        vector<char> str;
        vector<char> temp;
        string input; cin >> input;

        for (int i = 0; i < input.size(); i++) {
            char cur = input[i];
            if (cur == '-') {
                if (str.empty()) continue;
                str.pop_back();
            }
            else if (cur == '<') {
                if (!str.empty()) {
                    temp.push_back(str.back());
                    str.pop_back();
                }
            }
            else if (cur == '>') {
                if (!temp.empty()) {
                    str.push_back(temp.back());
                    temp.pop_back();
                }
            }
            else {
                str.push_back(cur);
            }
        }

        while (!temp.empty()) {
            str.push_back(temp.back());
            temp.pop_back();
        }

        for (int i = 0; i < str.size(); i++)
            cout << str[i];
        cout << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
