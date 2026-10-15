#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string solution(string s, string skip, int index) {
    bool pass[26] = {0};
    for (auto ch : skip) pass[ch - 'a'] = true;

    string ans = "";
    for (auto ch : s) {
        int cnt = 0;
        int plus = 0;
        int idx = ch - 'a';
        while (cnt < index) {
            if (pass[(idx + ++plus) % 26]) continue;
            cnt++;
        }
        ans += 'a' + (idx + plus) % 26;
    }
    return ans;
}

int main(void) {
    cout << solution("aukks", "wbqd", 5) << endl;
}
