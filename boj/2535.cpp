#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    int cnts[1001] = {0};
    vector<tuple<int, int, int>> v;
    while (N--) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({c, a, b});
    }
    sort(v.begin(), v.end(), greater<>());
    cout << get<1>(v[0]) << ' ' << get<2>(v[0]) << endl;
    cout << get<1>(v[1]) << ' ' << get<2>(v[1]) << endl;
    cnts[get<1>(v[0])]++;
    cnts[get<1>(v[1])]++;
    for (int i = 2; i < v.size(); i++) {
        if (cnts[get<1>(v[i])] != 2) {
            cout << get<1>(v[i]) << ' ' << get<2>(v[i]) << endl;
            return 0;
        }
    }
}
