#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long

ll gcd(int x, int y) {
    int a = x, b = y;
    ll temp;
    while (b) {
        temp = a;
        a = b;
        b = temp % b;
    }

    return a;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        ll sum = 0;
        int arr[101];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++)
                sum += gcd(arr[i], arr[j]);
        }
        cout << sum << endl;
    }
}
