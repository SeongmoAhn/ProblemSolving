#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define endl '\n'
#define SIZE 50

vector<int> temp, list;
bool visited[SIZE];
set<vector<int>> s;

int initInput() {
    int k; cin >> k;
    if (!k) return 1;

    for (int i = 0; i < k; i++) {
        int input; cin >> input;
        list.push_back(input);
    }

    return 0;
}

void dfs(int idx, int cnt) {
    if (cnt == 6) {
        s.insert(temp);
        // for (int i = 0; i < temp.size(); i++)
        //     cout << temp[i] << ' ';
        // cout << endl;
        return ;
    }

    for (int i = idx; i < list.size(); i++) {
        int cur = list[i];
        if (visited[cur]) continue;

        visited[cur] = 1;
        temp.push_back(cur);
        dfs(i + 1, cnt + 1);
        visited[cur] = 0;
        temp.pop_back();
    }
}

void solve() {
    while (1) {
        if (initInput()) return ;

        for (int i = 0; i < list.size(); i++)
            dfs(i, 0);

        vector<int> tmp;
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            tmp = *iter;
            for (int i = 0; i < 6; i++)
                cout << tmp[i] << ' ';
            cout << endl;
        }

        cout << endl;
        list.clear();
        fill(visited, visited + SIZE, 0);
        s.clear();
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
