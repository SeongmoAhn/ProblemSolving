#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(string s) {
    int alp[26]; fill(alp, alp + 26, -1);
    vector<int> ans;

    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'a';
        ans.push_back(alp[idx] == -1 ? -1 : i - alp[idx]);
        alp[idx] = i;
    }

    return ans;
}

int main(void) {
    for (int x : solution("banana")) cout << x << " ";
    cout << endl;
    for (int x : solution("foobar")) cout << x << " ";
    cout << endl;
}

