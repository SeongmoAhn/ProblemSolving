#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(string str) {
    vector<char> s;
    for (char ch : str) {
        if (s.empty()) {
            s.push_back(ch);
        } else {
            if (s.back() == ch) {
                s.pop_back();
            } else {
                s.push_back(ch);
            }
        }
    }

    return s.empty() ? 1 : 0;
}

int main(void) {
    cout << solution("baabaa") << endl;
    cout << solution("cdcd") << endl;
}
