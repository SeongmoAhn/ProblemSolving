#include <iostream>
using namespace std;

int n, m;
int arr[10];

void rec(int x, int len) {
    if (len == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = x; i <= n; i++) {
        arr[len] = i;
        rec(i + 1, len + 1);
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    rec(1, 0);

    return 0;
}
