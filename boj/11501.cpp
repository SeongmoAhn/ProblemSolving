#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long

ll solve()
{
    int N; cin >> N;
    vector<int> v;
    int n;
    while (N--) {
        cin >> n;
        v.push_back(n);
    }

    reverse(v.begin(), v.end());
    ll ans = 0;
    int pivot = -1;
    for (auto n : v) {
        if (n > pivot) {
            pivot = n;
            continue;
        }

        ans += (pivot - n);
    }

    return ans;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) {
        cout << solve() << endl;
    }

    return 0;
}
