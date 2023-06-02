#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main(void)
{
	int n, begin, end;
	vector<pair<int, int>> v;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		cin >> begin >> end;
		v.push_back({begin, end});
	}
	
	sort(v.begin(), v.end(), compare);
	
	int time = v[0].second;
	int count = 1;
	for (int i = 1 ;i < n; i++) {
		if (time <= v[i].first ) {
			count++;
			time = v[i].second;
		}
	}

	cout << count << '\n';
    return 0;
}
