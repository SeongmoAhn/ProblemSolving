#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, j, input;
    int mid;
    int sum = 0;
    vector<int> v;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    mid = (n - 1) / 2;

    cout << v[mid] << '\n';

	return 0;
}
