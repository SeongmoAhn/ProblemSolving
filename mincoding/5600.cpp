#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

int N, L;
vector<int> v;

void init_input() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
}

void solve() {
    int cnt = 1;
    int idx = 0;
    int cut = v[0] + L - 1;
    while (idx < N) {
        if (v[idx] > cut) {
            cut = v[idx] + L - 1;
            cnt++;
        }
        idx++;
    }

    cout << cnt;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    solve();

    return 0;
}
