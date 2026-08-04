#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    cout << llabs(n - m) << '\n';

	return 0;
}
