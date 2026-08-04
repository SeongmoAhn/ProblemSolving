#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    int sum = 0;
    int start = 0, end = 0, count = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (i = 0; i < n; i++) {
        cin >> input;
        v[i] = input;
    }

    sum = v[start];
    while (end < n) {
        if (sum == m) {
            count++;
            end++;
            sum += v[end];
        }
        else if (sum < m) {
            end++;
            sum += v[end];
        }
        else {
            sum -= v[start];
            start++;
        }

        if (start > end) {
            end = start;
            sum = v[start];
        }
    }

    cout << count << '\n';

	return 0;
}
