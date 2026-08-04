#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long 

int K, N;
vector<int> v;

void init_input()
{
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        int n; cin >> n;
        v.push_back(n);
    }
}

ll solve()
{
    sort(v.begin(), v.end());

    ll low = 1, high = v[K - 1], mid;
    ll cnt, ans;
    while (low <= high) {
        mid = (low + high) / 2;

        cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += v[i] / mid;
        }

        if (cnt >= N) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    cout << solve() << endl;

    return 0;
}
