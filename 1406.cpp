#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

string str;
int N;
vector<char> s, temp;

void initInput() {
    cin >> str >> N;
    for (int i = 0; i < str.length(); i++)
        s.push_back(str[i]);
}

void solve() {
    while (N--) {
        char cmd; cin >> cmd;

        if (cmd == 'L') {
            if (s.empty()) continue;

            temp.push_back(s.back());
            s.pop_back();
        }
        else if (cmd == 'D') {
            if (temp.empty()) continue;

            s.push_back(temp.back());
            temp.pop_back();
        }
        else if (cmd == 'B') {
            if (s.empty()) continue;

            s.pop_back();
        }
        else {
            char input; cin >> input;
            s.push_back(input);
        }
    }
    
    while (!temp.empty()) {
        s.push_back(temp.back());
        temp.pop_back();
    }

    for (int i = 0; i < s.size(); i++)
        cout << s[i];
    cout << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
