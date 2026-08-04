#include <iostream>
#include <map>
using namespace std;
#define endl '\n'
#define SIZE 

void solve() {
    int N, M;
    map<int, int> m;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        m[n]++;
    }

    while (M--) {
        int n; cin >> n;
        cout << m[n] << ' ';
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
