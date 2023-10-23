#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define SIZE 10001

int N, M;
int endd = -1;
int input[SIZE];
int ans;

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        endd = max(endd, input[i]);
    }
    cin >> M;
}

void bsearch(int start, int end) {
    if (start > end) return ;
    int mid = (start + end) / 2;
    ll result = 0;
    for (int i = 0; i < N; i++)
        result += ((input[i] - mid) >= 0 ? mid : input[i]);

    if (result <= M) {
        ans = mid;
        bsearch(mid + 1, end);
    }
    else bsearch(start, mid - 1);
}

void solve() {
    bsearch(1, endd);
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
