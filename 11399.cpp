#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> v;

void init_input()
{
    int N, n;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        v.push_back(n);
    }
}

int solve()
{
    int ans = 0;
    int temp = 0;
    sort(v.begin(), v.end());
    for (auto cur : v) {
        temp += cur;
        ans += temp;
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
