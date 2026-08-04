#include <iostream>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 1000001
#define INF 1e9

int n, k, cnt, maxLen;
int arr[SIZE];

void initInput() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve() {
    int start = 0, end = 0;
    if (arr[start] % 2) cnt++;

    while (1) {
        while (end < n - 1) {
            if (arr[end + 1] % 2) {
                if (cnt < k) cnt++;
                else break;
            }
            end++;
        }

        if (start == n || end == n) break;
        maxLen = max(maxLen, end - start + 1 - cnt);

        if (arr[start] % 2) cnt--;
        start++;
    }

    cout << maxLen << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
