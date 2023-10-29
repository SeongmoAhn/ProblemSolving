#include <iostream>
#include <stack>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    stack<int> s;
    while (N--) {
        int a; cin >> a;
        if (a == 1) { cin >> a; s.push(a); }
        else if (a == 2) { cout << (s.empty() ? -1 : s.top()) << endl; if(!s.empty()) s.pop(); }
        else if (a == 3) cout << s.size() << endl;
        else if (a == 4) cout << s.empty() << endl;
        else cout << (s.empty() ? -1 : s.top()) << endl;
    }
}
