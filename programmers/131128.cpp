#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string solution(string X, string Y) {
    int digit[10] = {0};
    int digit1[10] = {0};
    int digit2[10] = {0};
    for (auto ch : X) digit1[ch - '0']++;
    for (auto ch : Y) digit2[ch - '0']++;
    for (int i = 0; i < 10; i++) digit[i] = min(digit1[i], digit2[i]);

    string ans = "";
    for (int i = 9; i >= 0; i--) {
        while (digit[i]) {
            ans += '0' + i;
            digit[i]--;
        }
    }

    return !ans.size() ? "-1" : ans[0] == '0' ? "0" : ans;
}

int main(void) {
    cout << solution("100", "2345") << endl;
    cout << solution("100", "203045") << endl;
    cout << solution("100", "123450") << endl;
    cout << solution("12321", "42531") << endl;
    cout << solution("5525", "1255") << endl;
}
