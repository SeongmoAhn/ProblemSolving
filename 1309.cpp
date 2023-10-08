#include <iostream>
#include <tuple>
using namespace std;
#define endl '\n'
#define SIZE 100001
#define MOD 9901
#define tiii tuple<int, int, int>

int N;
tiii dp[SIZE];

void initInput() {
    cin >> N;
}

void solve() {
    dp[1] = {1, 1, 1};
    for (int i = 2; i <= N; i++) {
        int one, two, three;
        one = (get<0>(dp[i - 1]) + get<1>(dp[i - 1]) + get<2>(dp[i - 1])) % MOD;
        two = (get<0>(dp[i - 1]) + get<2>(dp[i - 1])) % MOD;
        three = (get<0>(dp[i - 1]) + get<1>(dp[i - 1])) % MOD;
        
        dp[i] = {one, two, three};
    }
    cout << (get<0>(dp[N]) + get<1>(dp[N]) + get<2>(dp[N])) % MOD << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
