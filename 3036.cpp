#include <iostream>
using namespace std;

void solve(int x, int y) {
    int a = x, b = y, temp;
    while (b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    cout << x / a << '/' << y / a << '\n';
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N, arr[101]; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 1; i < N; i++) solve(arr[0], arr[i]);
}
