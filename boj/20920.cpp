#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define endl '\n'

map<string, int> input;
int N, M;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp; cin >> temp;
        if (temp.size() >= M)
            input[temp]++;
    }
}

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.size() == b.first.size())
            return a.first < b.first;
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}

void solve() {
    vector<pair<string, int>> v(input.begin(), input.end());
    sort(v.begin(), v.end(), compare);
    for (auto str : v) {
        cout << str.first << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
