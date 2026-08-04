#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int, int>

int N;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

void initInput() {
    int N; cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
}

void solve() {
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < v.size(); i++) {
        if (pq.top() <= v[i].first) {
            pq.pop();
            pq.push(v[i].second);
        }
        else 
            pq.push(v[i].second);
    }

    cout << pq.size() << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
