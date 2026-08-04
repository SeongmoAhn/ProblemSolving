#include <iostream>
using namespace std;
#define endl '\n'

int N, T, P, ans;
int arr[6];

void initInput() {
    cin >> N;
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    cin >> T >> P;
}

void solve() {
    for (int i = 0; i < 6; i++) {
        ans += arr[i] / T + 1;
        if (!(arr[i] % T)) ans--;
    }
    cout << ans << endl;
    cout << N / P << ' ' << N % P << endl;
}

int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
