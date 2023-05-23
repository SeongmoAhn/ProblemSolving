#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    int input;
    int sum = 0;
    int i, j;
    vector<int> v;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    for (i = 0, j = n; i < n; i++, j--) {
        sum += v[i] * j;
    }

    cout << sum << '\n';

	return 0;
}
