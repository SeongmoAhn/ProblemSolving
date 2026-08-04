#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<pii> area;
    for (int i = 0; i < 6; i++) {
        int a, b; cin >> a >> b;
        area.push_back({a, b});
    }
    for (int i = 0; i < 6; i++) {
        if (area[i].first == area[(i + 2) % 6].first
        && area[(i + 1) % 6].first == area[(i + 5) % 6].first) {
            cout << N * (area[(i + 3) % 6].second * area[(i + 4) % 6].second - area[i].second * area[(i + 1) % 6].second) << '\n';
            return 0;
        }
    }
}
