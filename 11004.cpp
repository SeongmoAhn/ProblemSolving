#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N, M;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << v[M - 1];
}
