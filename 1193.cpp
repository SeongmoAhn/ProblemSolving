#include <iostream>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    cin >> n;

    for (i = 1; i < n; i++) {
        n -= i;
    }

    if (i % 2) { // 홀수 대각선
        cout << i + 1 - n << '/' << n << '\n';
    }
    else { // 짝수 대각선
        cout << n << '/' << i + 1 - n << '\n';
    }

    return 0;
}
