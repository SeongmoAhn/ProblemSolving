#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    pair<int, int> point;
    int count = 0;
    int result = 0;
    int cur;
    vector<pair<int, int>> v;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back({input, count++});
    }

    sort(v.begin(), v.end());
    cur = v[0].first;
    for (i = 0; i < n; i++) {
        if (v[i].first == cur) {
            v[i].first = result;
        }
        else {
            cur = v[i].first;
            v[i].first = ++result;
        }
    }

    sort(v.begin(), v.end(), compare);
    for (i = 0; i < n; i++) {
        cout << v[i].first << " ";
    }
    cout << '\n';

    return 0;
}
