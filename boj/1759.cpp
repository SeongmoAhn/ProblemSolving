#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

set<char> MO = {'a', 'e', 'i', 'o', 'u'};
int N, M;
vector<char> arr;
string str = "";

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        char input; cin >> input;
        arr.push_back(input);
    }
}

bool check() {
    int mo = 0;
    for (int i = 0; i < N; i++) {
        if (MO.find(str[i]) != MO.end())
            mo++;
    }
    return mo >= 1 && (N - mo) >= 2;
}

void dfs(int idx, int size) {
    if (size == N) {
        if (check()) {
            cout << str << endl;
        }
        return ;
    }

    for (int i = idx; i < M; i++) {
        str.push_back(arr[i]);
        dfs(i + 1, size + 1);
        str.pop_back();
    }
}

void solve() {
    sort(arr.begin(), arr.end());
    dfs(0, 0);
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
