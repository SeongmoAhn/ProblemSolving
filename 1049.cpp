#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, M, ans;
vector<int> sixArr, oneArr;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int lines, line; cin >> lines >> line;
        sixArr.push_back(lines);
        sixArr.push_back(line * 6);
        oneArr.push_back(line);
    }
    sort(sixArr.begin(), sixArr.end());
    sort(oneArr.begin(), oneArr.end());
}

void solve() {
    while (1) {
        if (N >= 6) {
            ans += sixArr[0];
            N -= 6;
        }
        else {
            int cur = min(oneArr[0] * N, sixArr[0]);
            ans += cur;
            cout << ans << endl;
            return ;
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
