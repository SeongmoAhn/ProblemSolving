#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, C, ans = 0;
vector<int> house;

void initInput() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        house.push_back(input);
    }
    sort(house.begin(), house.end());
}

void solve() {
    int start = 1, mid, end = house[N - 1] - house[0];

    while (start <= end) {
        mid = (start + end) / 2;
        int cnt = 1;
        int prev = house[0];
        for (int i = 1; i < N; i++) {
            if (house[i] - prev >= mid) {
                cnt++;
                prev = house[i];
            }
        }

        if (cnt >= C) {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
