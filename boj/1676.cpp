#include <iostream>
using namespace std;

int n;
int cnt;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    int i = 5;

    while (i <= n) {
        cnt += n / i;
        i *= 5;
    }

    cout << cnt << '\n';

	return 0;
}
