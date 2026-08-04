#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'

int N;
deque<int> dq;

void initInput() {
    cin >> N;
}

void solve() {
    int input;
    while (N--) {
        cin >> input;

        if (input == 1) {
            int X; cin >> X;
            dq.push_front(X);
        }
        else if (input == 2) {
            int X; cin >> X;
            dq.push_back(X);
        }
        else if (input == 3) {
            if (dq.empty()) { cout << -1 << endl; }
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (input == 4) {
            if (dq.empty()) { cout << -1 << endl; }
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (input == 5) {
            cout << dq.size() << endl;
        }
        else if (input == 6) {
            cout << dq.empty() << endl;
        }
        else if (input == 7) {
            if (dq.empty()) { cout << -1 << endl; }
            else { cout << dq.front() << endl; }
        }
        else {
            if (dq.empty()) { cout << -1 << endl; }
            else { cout << dq.back() << endl; }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
