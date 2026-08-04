#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 501
#define INF 1e9

int T;

void initInput() {
    cin >> T;
}

void solve() {
    while (T--) {
        int N; cin >> N;
        int input[SIZE] = {0, };
        int dp[SIZE][SIZE] = {0, };
        for (int i = 1; i <= N; i++) { 
            int a; cin >> a;
            input[i] = input[i - 1] + a;
        }

        for (int i = 1; i < N; i++) {
            for (int y = 1; y <= N - i; y++) {
                int x = y + i;
                dp[y][x] = INF;

                for (int k = y; k < x; k++)
                    dp[y][x] = min(dp[y][x], dp[y][k] + dp[k + 1][x] + input[x] - input[y - 1]);
            }
        }
        cout << dp[1][N] << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
