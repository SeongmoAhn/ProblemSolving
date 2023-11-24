#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 1010

int N;
int input[SIZE], dp1[SIZE], dp2[SIZE];
int ans = -1;

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (input[i] > input[j]) dp1[i] = max(dp1[i], dp1[j]);
        }
        dp1[i]++;
    }
    for (int i = N; i >= 1; i--) {
        for (int j = i + 1; j <= N; j++) {
            if (input[i] > input[j]) dp2[i] = max(dp2[i], dp2[j]);
        }
        dp2[i]++;
    }
    for (int i = 1; i <= N; i++) ans = max(ans, dp1[i] + dp2[i]);
    cout << ans - 1 << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
