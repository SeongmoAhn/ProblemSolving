#include <iostream>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;
    int arr[100001];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int cnt = 1, cur = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] > cur) {
            cnt++;
            cur = arr[i];
        } 
    }
    cout << cnt;
}
