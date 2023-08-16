#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 53
#define MOD 10007

int N, ans;
int nCk[SIZE][SIZE];

void initInput() {
    cin >> N;
}

void makeCombination() {
    nCk[0][0] = nCk[1][0] = nCk[1][1] = 1;
    for (int i = 2; i <= 52; i++) {
        nCk[i][0] = nCk[i][i] = 1;
        for (int j = 1; j <= i / 2; j++) {
            nCk[i][j] = nCk[i][i - j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % MOD;
        }
    }
}

void solve() {
    makeCombination();

    for (int i = 4; i <= N; i += 4) {
        if ((i / 4) % 2 == 1) {
            ans = (ans + nCk[13][i / 4] * nCk[52 - i][N - i]) % MOD;
        }
        else {
            ans = (ans- nCk[13][i / 4] * nCk[52 - i][N - i]) % MOD;
        }

        if (ans < 0) ans += MOD;
    }
    cout << ans % MOD << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
