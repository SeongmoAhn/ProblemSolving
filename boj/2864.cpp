#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    string s1, s2; cin >> s1 >> s2;
    string s1M = "", s1m = "", s2M = "", s2m = "";
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '5') {
            s1M += '6';
            s1m += '5';
        }
        else if (s1[i] == '6') {
            s1M += '6';
            s1m += '5';
        }
        else {
            s1M += s1[i];
            s1m += s1[i];
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '5') {
            s2M += '6';
            s2m += '5';
        }
        else if (s2[i] == '6') {
            s2M += '6';
            s2m += '5';
        }
        else {
            s2M += s2[i];
            s2m += s2[i];
        }
    }
    cout << stoi(s1m) + stoi(s2m) << ' ' << stoi(s1M) + stoi(s2M);
}
