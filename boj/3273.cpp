#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i;
    int count = 0, sum;
    vector<int> v;
    cin >> n;
    int start = 0, end = n - 1;
    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    cin >> m;
    sort(v.begin(), v.end());

    while (start < end) {
        sum = v[start] + v[end];
        if (sum == m) {
            count++;
            start++;
            end--;
        }
        else if (sum < m) {
            start++;
        }
        else {
            end--;
        }
    }

    cout << count << '\n';

    return 0;
}
