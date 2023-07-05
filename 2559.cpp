#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 100001

int N, M, ans, sum;
int arr[SIZE];

void initInput() {
    cin >> N >> M;
    for (int i = 0 ; i < N; i++) cin >> arr[i];
}

void solve() {
    int i, j;
    for (i = 0; i < M; i++) sum += arr[i];
    ans = sum;
    j = i; i = 0;

    while (j < N) {
        sum -= arr[i++];
        sum += arr[j++];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
