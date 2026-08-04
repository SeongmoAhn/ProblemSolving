#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define SIZE 501

int N;
int dp[SIZE][SIZE];
int matrix[SIZE][2];

void initInput() {
    cin >> N;
    int a, b;
    for (int i = 1; i <= N; i++)  {
        cin >> a >> b;
        matrix[i][0] = a;
        matrix[i][1] = b;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++)
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
        }
    }
    cout << dp[1][N];
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
