#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'
#define pii pair<int, int>

int N;
deque<pii> dq;

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        dq.push_back({a, i});
    }
}

void solve() {
    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();
        cout << cur.second << ' ';

        if (cur.first> 0) {
            for (int i = 0; i < cur.first - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
             }
        }
        else {
            for (int i = 0; i < -cur.first; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
