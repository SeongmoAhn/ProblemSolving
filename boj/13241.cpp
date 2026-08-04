#include <iostream>
using namespace std;

int main(void) {
    // freopen("input.txt", "r", stdin);
    long long a, b; cin >> a >> b;
    long long x = a, y = b, temp;
    while (y) {
        temp = x;
        x = y;
        y = temp % x;
    }
    cout << a * b / x;
}
