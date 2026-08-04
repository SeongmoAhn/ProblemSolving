#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

int N, M;
map<int, vector<string>> m;

void init_input() {
    cin >> N >> M;
    while (N--) {
        vector<string> temp;
        int id; cin >> id;
        for (int i = 0; i < 5; i++) {
            string str; cin >> str;
            temp.push_back(str);
        }
        m[id] = temp;
    }
}

void solve() {
    map<string, int> op = { {"language", 1}, {"math", 2}, {"science", 3}, {"sociology", 4}, };
    while (M--) {
        int id; cin >> id;
        string str; cin >> str;
        cout << m[id][0] << ' ' << m[id][op[str]] << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    solve();

    return 0;
}
