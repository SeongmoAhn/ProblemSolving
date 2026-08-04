#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1001
#define RED 0
#define GREEN 1
#define BLUE 2

int n;
int dp[SIZE][3] = {0};

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int redCost, greenCost, blueCost;
        cin >> redCost >> greenCost >> blueCost;
        dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + redCost;
        dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + greenCost;
        dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + blueCost;
    }
}

void solve() {
    cout << min(dp[n][RED], min(dp[n][GREEN], dp[n][BLUE])) << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
