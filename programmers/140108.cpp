#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(string s) {
    char cur;
    int cnt = 0;
    int same = 0, diff = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!same && !diff) {
            cur = s[i];
            same++;
            continue;
        }

        cur == s[i] ? same++ : diff++;

        if (same == diff) {
            same = diff = 0;
            cnt++;
        }
    }
    if (same != diff) cnt++;

    return cnt;
}

int main(void) {
    cout << solution("banana") << endl;
    cout << solution("abracadabra") << endl;
    cout << solution("aaabbaccccabba") << endl;
}
