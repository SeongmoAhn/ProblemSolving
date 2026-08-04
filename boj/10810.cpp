#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input;
    int n, m, i, j, k;
    vector<int> v(101);
    cin >> n >> m;

    for (int testCase = 0; testCase < m; testCase++) {
        cin >> i >> j >> k;
        for (; i <= j; i++) {
            v[i] = k;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << '\n';

	return 0;
}
