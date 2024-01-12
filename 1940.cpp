#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, M, cnt;
vector<int> v;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
}

void solve() {
    int i = 0, j = v.size() - 1;
    while (i < v.size() - 1) {
        while (i < j) {
            if (v[i] + v[j] == M) cnt++;
            j--;
        }
        j = v.size() - 1;
        i++;
    }
    cout << cnt;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
