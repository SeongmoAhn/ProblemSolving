#include <iostream>
#include <deque>
#include <string>
using namespace std;
#define endl '\n'

void solve() {
    int N; cin >> N;
    deque<int> dq;
    while (N--) {
        string str; cin >> str;
        if (str == "push_front") {
            int n; cin >> n;
            dq.push_front(n);
        } else if (str == "push_back") {
            int n; cin >> n;
            dq.push_back(n);
        } else if (str == "pop_front") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        } else if (str == "pop_back") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        } else if (str == "size") {
            cout << dq.size() << endl;
        } else if (str == "empty") {
            cout << dq.empty() << endl;
        } else if (str == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << endl;
        } else {
            cout << (dq.empty() ? -1 : dq.back()) << endl;
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
