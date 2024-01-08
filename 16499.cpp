#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    string str;
    set<string> s;
    while (N--) {
        cin >> str;
        sort(str.begin(), str.end());
        s.insert(str);
    }
    cout << s.size();
}
