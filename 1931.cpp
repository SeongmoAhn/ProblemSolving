#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, begin, end, i;
	vector<pair<int, int>> v;
	cin >> n ;
	for (i = 0; i < n; i++) {
		cin >> begin >> end;
		v.push_back({begin, end});
	}
	sort(v.begin(), v.end(), compare);
	
	int endTime = v[0].second;
	int count = 1;
	for (i = 1; i < n; i++) {
		if (endTime <= v[i].first ) {
			count++;
			endTime = v[i].second;
		}
	}

	cout << count << '\n';
    return 0;
}
