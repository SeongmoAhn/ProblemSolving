#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define pii pair<int, int>

int N, d, ans;
vector<pii> ho;
priority_queue<int> pq;

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int home, office;
        cin >> home >> office;
        home < office ? ho.push_back({home, office}) : ho.push_back({office, home});
    }
    cin >> d;
}

bool compare(pii &a, pii &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    sort(ho.begin(), ho.end(), compare);

    for (int i = 0; i < ho.size(); i++) {
        int start = ho[i].first;
        int end = ho[i].second;
        if (end - start <= d) pq.push(-start);
        else continue;

        while (!pq.empty()) {
            if (-pq.top() >= end - d) {
                ans = max(ans, (int)pq.size());
                break;
            }
            else pq.pop();
        }
    }

    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
