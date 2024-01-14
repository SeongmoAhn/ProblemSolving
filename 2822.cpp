#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int sum = 0;
    priority_queue<pair<int, int>> pq;
    vector<int> v;
    for (int i = 1; i <= 8; i++) {
        int a; cin >> a;
        pq.push({a, i});
    }
    for (int i = 0; i < 5; i++) {
        sum += pq.top().first;
        v.push_back(pq.top().second);
        pq.pop();
    }
    cout << sum << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < 5; i++)
        cout << v[i] << ' ';
}
