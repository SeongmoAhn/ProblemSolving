#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 1000001

int N, ans;
int arr[SIZE];

int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < 31; i++) {
        int bit = (1 << i), temp = 0;

        for (int j = 0; j < N; j++)
            if (bit & arr[j])
                temp++;

        ans = max(ans, temp);
    }

    cout << ans;
}
