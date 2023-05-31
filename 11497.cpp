#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    cin >> n;

    for (i = 0; i < n; i++) {
        vector<int> v;
        vector<int> result;
        int level = 0;
        cin >> m;
        for (j = 0; j < m; j++) {
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < m; i += 2) {
            result.push_back(v[i]); 
        }
        for (int i = m - 1; i > 0; i--) {
            if (i % 2 == 1)
                result.push_back(v[i]);
        }

        for (int i = 0; i < m - 1; i++) {
            level = max(level, abs(result[i] - result[i + 1]));
        }
        level = max(level, result[m - 1] - result[0]);

        cout << level << '\n';
    }

    return 0;
}
