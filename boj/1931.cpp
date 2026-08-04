#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define pii pair<int, int>

bool compare(pii a, pii b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int solve()
{
    int N; cin >> N;
    vector<pii> v;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }

    sort(v.begin(), v.end(), compare);

    int ans = 0;
    int last = v[0].first;
    for (auto cur : v) {
        cout << cur.first << ", " << cur.second << endl;
        if (cur.first <= last) {
            ans++;
            last = cur.second;
        }
    }

    return ans;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cout << solve() << endl;

    return 0;
}
