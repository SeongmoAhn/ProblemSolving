#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(string t, string p) {
    int cnt = 0;
    for (int i = 0; i < t.size() - p.size() + 1; i++) {
        string tmp = t.substr(i, p.size());

        if (tmp <= p) cnt++;
    }

    return cnt;
}

int main(void) {
    cout << solution("3141592", "271") << endl;
    cout << solution("500220839878", "7") << endl;
    cout << solution("10203", "15") << endl;
}
