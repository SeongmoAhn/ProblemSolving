#include <iostream>
#include <string>
#include <set>
using namespace std;
#define endl '\n'

int N, M, ans;
set<string> se;

void initInput() {
    cin >> N >> M;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        se.insert(input);
    }
}

void solve() {
    string input;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (se.find(input) != se.end()) ans++;
    }
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
