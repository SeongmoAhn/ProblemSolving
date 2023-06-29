#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 2001

int n, m;
int number[SIZE];
bool dp[SIZE][SIZE];

void initInput() {
    cin >> n;
    int input;
    for (int i = 1; i <= n; i++) {
        cin >> number[i];
        dp[i][i] = true;

        if (number[i] == number[i - 1] && i > 1) 
            dp[i - 1][i] = true;
    }
    cin >> m;
}

void solve() {
    int cnt = n - 2;
    for (int i = 1; i <= cnt; i++) {
        int cur = 1;
        for (int j = i + 2; j <= n; j++, cur++) {
            if (number[cur] == number[j] && dp[cur + 1][j - 1])
                dp[cur][j] = true;
        }
    }

    int s, e;
    while (m--) {
        cin >> s >> e;
        cout << dp[s][e] << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
