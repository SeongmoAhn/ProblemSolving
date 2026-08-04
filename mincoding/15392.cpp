#include <iostream>
#include <map>
using namespace std;
#define endl '\n'

void solve() {
    int N; cin >> N;
    map<int, int> m;
    while (N--) {
        string op; cin >> op;
        int K, V;
        if (op == "insert") {
            cin >> K >> V;
            m[K] += V;
        } else if (op == "get") {
            cin >> K;
            cout << (m.count(K) ? m[K] : 0) << endl;
        } else if (op == "remove") {
            cin >> K;
            m.erase(K);
        } else if (op == "size") {
            cout << m.size() << endl;
        } else {
            cout << m.empty() << endl;
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
