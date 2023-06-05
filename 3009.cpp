#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vx;
vector<int> vy;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        vx.push_back(x);
        vy.push_back(y);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    int x, y;
    if (vx[0] == vx[1]) x = vx[2];
    else x = vx[0];

    if (vy[0] == vy[1]) y = vy[2];
    else y = vy[0];

    cout << x << ' ' << y << '\n';

    return 0;
}
