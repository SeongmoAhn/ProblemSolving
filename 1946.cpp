#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int, int>

int T, N;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<pii> v;
        for (int i = 0; i < N; i++) {
            int a, b; cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int maxVal = v[0].second;
        int cnt = 1;
        for (int i = 1; i < v.size(); i++) {
            v[i].second < maxVal && (cnt++ && (maxVal = v[i].second));
        }
        cout << cnt << endl;
    }

    return 0;
}
