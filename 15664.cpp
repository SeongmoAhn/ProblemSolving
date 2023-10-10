#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define endl '\n'
#define SIZE 10001

int N, M;
vector<int> temp;
set<vector<int>> ans;
vector<int> input;
int visited[SIZE];

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        input.push_back(a);
        visited[a]++;
    }
    sort(input.begin(), input.end());
}

void dfs(int idx, int cnt) {
    if (cnt == M) {
        ans.insert(temp);
        return ;
    }

    for (int i = idx; i < input.size(); i++) {
        if (!visited[input[i]]) continue;
        temp.push_back(input[i]);
        dfs(i + 1, cnt + 1);
        visited[input[i]]++;
        temp.pop_back();
    }
}

void solve() {
    for (int i = 0; i < input.size(); i++) {
        visited[input[i]]--;
        temp.push_back(input[i]);
        dfs(i + 1, 1);
        visited[input[i]]++;
        temp.pop_back();
    }

    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        temp = *iter;
        for (int j = 0; j < M; j++) {
            cout << temp[j] << ' ';
        }
        cout << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
