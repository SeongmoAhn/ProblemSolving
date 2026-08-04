#include <algorithm>
#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    else {
        return p1.second < p2.second;
    }
}

int main(void)
{
    int n, i;
    cin >> n;
    vector<pair<int, int>> v;
    pair<int, int> input;

    for (i = 0; i < n; i++) {
        cin >> input.first >> input.second;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), compare);
    for (i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

	return 0;
}
