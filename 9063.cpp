#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, y;
vector<int> vx;
vector<int> vy;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vx.push_back(x);
        vy.push_back(y);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    cout << (vx[n - 1] - vx[0]) * (vy[n - 1] - vy[0]) << '\n';

    return 0;
}
