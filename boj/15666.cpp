#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define endl '\n'
#define SIZE 

int N, M;
vector<int> arr;
vector<int> temp;
set<vector<int>> s;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
}

void dfs(int idx) {
    if (temp.size() == M) {
        s.insert(temp);
        return ;
    }
    for (int i = idx; i < N; i++) {
        temp.push_back(arr[i]);
        dfs(i);
        temp.pop_back();
    }
}

void solve() {
    dfs(0);
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        for (int i = 0; i < M; i++) {
            cout << (*iter)[i] << ' ';
        } cout << endl;
    }

    return 0;
}
