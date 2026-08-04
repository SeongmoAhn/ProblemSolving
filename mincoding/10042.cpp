#include <iostream>
#include <set>
using namespace std;
#define endl '\n'

// 짝수 들어오면 BST에 삽입
// 홀수 들어오면 해당 수보다 작은 가장 큰 짝수 출력
void solve() {
    int N; cin >> N;
    set<int> s;
    while (N--) {
        int n; cin >> n;
        if (n % 2) {
            auto iter = s.upper_bound(n);
            cout << (iter == s.end() ? -1 : *iter) << ' ';
        } else {
            s.insert(n);
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
