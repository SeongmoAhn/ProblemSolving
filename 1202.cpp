#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 300001

int n, k;
int bag[SIZE];
pii gem[SIZE];
priority_queue<int> pq;
ll ans;

void initInput() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> gem[i].first >> gem[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> bag[i];
    }
    sort(gem, gem + n);
    sort(bag, bag + k);
}

ll solve() {
    int idx = 0;
    ll sum = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && bag[i] >= gem[idx].first) {
            pq.push(gem[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    cout << solve() << endl;

    return 0;
}
