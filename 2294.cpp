#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 100010
#define INF 1e9

int dp[SIZE];
vector<int> coins;
int N, K;

void initInput() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int coin; cin >> coin;
        coins.push_back(coin);
    } 
}

void solve() {
    fill(dp, dp + SIZE, INF);

    for (int i = 0; i < coins.size(); i++)
        dp[coins[i]] = 1;
    dp[0] = 0;

    for (int i = 1; i <= K; i++){
        for (int j = 0; j < coins.size(); j++) {
            if ((i - coins[j]) >= 0)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    cout << ((dp[K] == INF) ? -1 : dp[K]) << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
