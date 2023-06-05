#include <iostream>
#include <cmath>
using namespace std;

int testCase;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        int x1, y1, r1;
        int x2, y2, r2;
        double d;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        int r = min(r1, r2), R = max(r1, r2);

        if (r == R && d == 0)
            cout << -1 << '\n';
        else if (R - r > d || R + r < d)
            cout << 0 << '\n';
        else if (R + r == d || R - r == d)
            cout << 1 << '\n';
        else if (R + r > d || R - r < d)
            cout << 2 << '\n';
    }

    return 0;
}
