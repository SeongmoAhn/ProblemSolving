#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int start = 0, end = n - 1;
    int minValue = 2000000001;
    pair<int, int> point;
    while (1) {
        int sum = v[start] + v[end];
        if (abs(sum) < minValue) {
            minValue = abs(sum);
            point.first = v[start];
            point.second = v[end];
        }

        if (sum < 0)
            start++;
        else if (sum > 0)
            end--;
        else {
            cout << v[start] << " " << v[end] << '\n';
            return 0;
        }

        if (start == end)
            break;
    }
    cout << point.first << " " << point.second << '\n';

    return 0;
}
