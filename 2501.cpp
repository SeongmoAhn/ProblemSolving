#include <iostream>
#include <vector>
using namespace std;

int a, b;
int cnt;
vector<int> v;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            v.push_back(i);
            cnt++;
        }
    }
    if (cnt < b) {
        cout << 0 << '\n';
    }
    else
        cout << v[b - 1] << '\n';

    return 0;
}
