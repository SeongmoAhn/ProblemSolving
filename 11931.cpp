#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    vector<int> v;
    int N, n; cin >> N;
    while (N--) { cin >> n; v.push_back(n); }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << '\n';
}
