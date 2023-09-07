#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 301

int N, M, T;
int arr[SIZE][SIZE];

void initInput() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
}

void solve() {
    cin >> T;
    while (T--) {
        int sum = 0;
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int i = a; i <= c; i++) {
            for (int j = b; j <= d; j++) {
                if (i == c && j > d) continue;
                sum += arr[i][j];
            }
        }
        cout << sum << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
