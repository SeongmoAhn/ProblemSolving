#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1000001
#define ll long long

ll prime[SIZE];

void solve() {
    for (int i = 1; i < SIZE; i++) {
        for (int j = i; j < SIZE; j += i)
            prime[j] += i;
        prime[i] += prime[i - 1];
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << prime[N] << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();
}
