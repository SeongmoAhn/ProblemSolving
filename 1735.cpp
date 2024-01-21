#include <iostream>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = a * d + b * c;
    int f = b * d;
    int x = e, y = f, temp;
    while (y) {
        temp = x;
        x = y;
        y = temp % x;
    }
    cout << e / x << ' ' << f / x;
}
