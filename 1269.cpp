#include <iostream>
#include <set>
using namespace std;
#define endl '\n'

int N, M;
set<int> s1, s2;

void initInput() {
    cin >> N >> M;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        s1.insert(input);
    }
    for (int i = 0; i < M; i++) {
        cin >> input;
        s2.insert(input);
    }
}

void solve() {
    int cnt = 0;
    for (auto iter = s1.begin(); iter != s1.end(); iter++) {
        if (s2.find(*iter) == s2.end()) continue;
        cnt++;
    }
    cout << s1.size() + s2.size() - 2 * cnt << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
