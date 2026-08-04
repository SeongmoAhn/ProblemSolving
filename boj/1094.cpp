#include <iostream>
using namespace std;
#define endl '\n'

int stick[] = {64, 32, 16, 8, 4, 2, 1};
int N, cnt;

void initInput() {
    cin >> N;
}

void solve() {
    int idx = 0;
    while (N) {
        if (N >= stick[idx]) {
            N -= stick[idx];
            cnt++;
        }
        idx++;
    }
    cout << cnt;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
