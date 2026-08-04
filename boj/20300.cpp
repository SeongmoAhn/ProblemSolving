#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
#define ll long long

int N;
priority_queue<ll> pq1, pq2;

void init_input()
{
    cin >> N;
    ll n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        pq1.push(n);
        pq2.push(-n);
    }
}

ll solve()
{
    ll ans = -1;
    if (N & 1) {
        ans = pq1.top();
        pq1.pop();
    }

    for (int i = 0; i < (N / 2); i++) {
        ll sum = pq1.top() + (-pq2.top());
        pq1.pop();
        pq2.pop();
        ans = max(ans, sum);
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
