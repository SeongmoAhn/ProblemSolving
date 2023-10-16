#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'
#define tp tuple<string, int, int, int>

int N;
vector<tp> v;

bool compare(tp t1, tp t2) {
    if (get<1>(t1) == get<1>(t2)) {
        if (get<2>(t1) == get<2>(t2)) {
            if (get<3>(t1) == get<3>(t2)) {
                return get<0>(t1) < get<0>(t2);
            }
            return get<3>(t1) > get<3>(t2);
        }
        return get<2>(t1) < get<2>(t2);
    }
    return get<1>(t1) > get<1>(t2);
}

void initInput() {
    cin >> N;
    string name;
    int ko, en, ma;
    for (int i = 0; i < N; i++) {
        cin >> name >> ko >> en >> ma;
        v.push_back({name, ko, en, ma});
    }
}

void solve() {
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++)
        cout << get<0>(v[i]) << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
