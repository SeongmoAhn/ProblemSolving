#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, M;
vector<int> v;

void init_input()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    cin >> M;
}

bool bs(int low, int high, int n) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] > n) high = mid - 1;
        else if (v[mid] < n) low = mid + 1;
        else return 1;
    }
    return 0;
}

void solve()
{
    while (M--) {
        int n; cin >> n;
        // cout << binary_search(v.begin(), v.end(), n) << endl;
        cout << bs(0, N - 1, n) << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    solve();

    return 0;
}
