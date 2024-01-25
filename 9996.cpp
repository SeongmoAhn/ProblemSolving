#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    string s; cin >> s;
    string front = "", rear = "";
    int i = 0;
    while (s[i] != '*') front += s[i++];
    i++;
    while (i < s.size()) rear += s[i++];

    while (T--) {
        string input; cin >> input;
        bool flag = 1;
        if (s.size() - 1 > input.size()) flag = 0;
        for (int i = 0; i < front.size(); i++) {
            if (input[i] != front[i]) {
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < rear.size(); i++) {
            if (input[input.size() - 1 - i] != rear[rear.size() - 1 - i]) {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "DA" : "NE") << '\n';
    }
}
