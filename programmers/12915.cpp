#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string &a, const string &b) {
        if (a[n] != b[n]) return a[n] < b[n];
        return a < b;
    });
    return strings;
}

int main(void) {
    for (string s : solution({"sun", "bed", "car"}, 1)) cout << s << " ";
    cout << endl;
    for (string s : solution({"abce", "abcd", "cdx"}, 2)) cout << s << " ";
    cout << endl;
}
