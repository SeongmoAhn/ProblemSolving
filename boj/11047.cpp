#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, K;
vector<int> v;

void init_input()
{
    cin >> N >> K;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n; v.push_back(n);
    }
}

int solve()
{
    reverse(v.begin(), v.end());

    int ans = 0;
    for (auto coin : v) {
        ans += (K / coin);
        K %= coin;
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
