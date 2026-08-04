#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define INF 1e9

int N, sum;
vector<pii> v;
vector<int> dist1, dist2;

void initInput() {
    cin >> N;
    pii before = make_pair(0, 0);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        if (i) {
            dist1.push_back(abs(before.first - a) + abs(before.second - b));
            sum += dist1[i - 1];
        }
        before = make_pair(a, b);
    }
}

void solve() {
    for (int i = 0; i < v.size() - 2; i++)
        dist2.push_back(abs(v[i].first - v[i + 2].first) + abs(v[i].second - v[i + 2].second));

    int m = 0;
    for (int i = 0; i < v.size() - 2; i++)
        m = max(m, dist1[i] + dist1[i + 1] - dist2[i]);

    cout << sum - m;
}

int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
