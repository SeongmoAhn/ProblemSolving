#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int N, ans;
priority_queue<int, vector<int>, greater<>> pq;

void initInput() {
    cin >> N;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a; pq.push(a);
    }
}

void solve() {
    while (pq.size() >= 2) {
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a + b);
        ans += (a + b);
    }
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
