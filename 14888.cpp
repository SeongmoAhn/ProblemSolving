#include <iostream>
#include <algorithm>
using namespace std;

int n, maxValue = -2100000000, minValue = 2100000000;
int input[12], oper[4], visited[12];

void solve(int ans, int idx) {
    if (idx == n) { // 모든 연산자 사용
        maxValue = max(maxValue, ans);
        minValue = min(minValue, ans);
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i]--;

            if (i == 0) solve(ans + input[idx], idx + 1);
            else if (i == 1) solve(ans - input[idx], idx + 1);
            else if (i == 2) solve(ans * input[idx], idx + 1);
            else solve(ans / input[idx], idx + 1);

            oper[i]++;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i];
    for (int i = 0; i < 4; i++) cin >> oper[i];

    solve(input[0], 1);
    cout << maxValue << '\n' << minValue << '\n';

    return 0;
}
