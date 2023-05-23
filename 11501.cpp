#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase, n, input, i, j, k, size;
    long long sum = 0;
    int maxValue;
    cin >> testCase;
    vector<int> v;

    for (i = 0; i < testCase; i++) {
        cin >> n;
        v.clear();
        maxValue = -1;
        sum = 0;
        for (j = 0; j < n; j++) {
            cin >> input;
            v.push_back(input);
        }

        for (j = n - 1; j >= 0; j--) {
            if (maxValue < v[j]) {
                maxValue = v[j];
            }
            else {
                sum += maxValue - v[j];
            }
        }
        cout << sum << '\n';
    }

	return 0;
}
