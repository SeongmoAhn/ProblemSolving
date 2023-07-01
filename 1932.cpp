#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 501

int N;
int map[SIZE][SIZE];
int dp[SIZE][SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    dp[1][1] = map[1][1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j]; 
        }
    }

    int maxValue = -1;
    for (int i = 1; i <= N; i++) {
        maxValue = max(maxValue, dp[N][i]);
    }
    cout << maxValue << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
