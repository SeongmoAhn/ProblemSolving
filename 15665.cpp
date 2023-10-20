#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define endl '\n'

int N, M;
set<int> s;
set<vector<int>> ans;
vector<int> input;
vector<int> temp;

void dfs(int idx, int cnt) {
    if (temp.size() == M) {
        ans.insert(temp);
        return;
    }

    for (int i = 0; i < input.size(); i++) {
        temp.push_back(input[i]);
        dfs(i, cnt + 1);
        temp.pop_back();
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    for (auto iter = s.begin(); iter != s.end(); iter++)
        input.push_back(*iter);
    s.clear();

    for (int i = 0; i < input.size(); i++)
        dfs(i, 0);

    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        temp = *iter;
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << ' ';
        cout << endl;
    }

    return 0;
}
