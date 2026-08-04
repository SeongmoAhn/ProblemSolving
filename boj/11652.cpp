#include <iostream>
#include <map>
using namespace std;
#define endl '\n'
#define ll long long

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    ll N, ans = 0, ansCnt = 0; cin >> N;
    map<ll, int> m;
    while (N--) {
        ll a; cin >> a;
        m[a]++;
    }
    for (auto iter : m) {
        if (iter.second > ansCnt) {
            ansCnt = iter.second;
            ans = iter.first;
        }
    }
    cout << ans;
}
