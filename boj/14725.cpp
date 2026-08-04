#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
#define endl '\n'
#define SIZE 1001

int N;
set<string> s;

void initInput() {
    cin >> N;

    while (N--) {
        int M; cin >> M;
        string str = "";

        while (M--) {
            string input; cin >> input;
            str += "-" + input;
            s.insert(str);
        }
    }
}

void solve() {
    for (auto iter : s){
        int cnt = count(iter.begin(), iter.end(), '-');
        int pos = iter.find_last_of("-");
        string str = iter.substr(pos + 1);
        for (int i = 0; i < cnt - 1; i++) cout << "--";
        cout << str << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
