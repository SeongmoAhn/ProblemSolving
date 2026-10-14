#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int solution(string s) {
    map<string, int> m = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    int ans = 0;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
        } else {
            temp += s[i];

            if (m.count(temp)) {
                ans = ans * 10 + m[temp];
                temp = "";
            }
        }
    }

    return ans;
}

int main(void) {
    cout << solution("one4seveneight") << endl;
    cout << solution("23four5six7") << endl;
    cout << solution("2three45sixseven") << endl;
    cout << solution("123") << endl;
}