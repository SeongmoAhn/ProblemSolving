#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define SIZE 201

int N, M, sum;
int arr[SIZE][2];
int dp[SIZE][SIZE][3];

void initInput() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 3; j++)
            dp[i][0][j] = INF;
    }
}

void solve() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + arr[j][0];
            dp[i][j][1] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[j][1];
            dp[i][j][2] = min(min(dp[i][j - 1][0], dp[i][j - 1][1]), dp[i][j - 1][2]);
        }
    }
    
    cout << sum - min(min(dp[M][N][0], dp[M][N][1]), dp[M][N][2]);
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
