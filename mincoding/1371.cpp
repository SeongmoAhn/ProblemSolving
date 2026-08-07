#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a[26] = {0};
    string s = "MINCODING";
    for (int i = 0; i < s.size(); i++) { a[s[i] - 'A'] = 1; }
    int N; cin >> N;
    while (N--) {
        char c; cin >> c;
        cout << (a[c - 'A'] ? 'O' : 'X');
    }
}
