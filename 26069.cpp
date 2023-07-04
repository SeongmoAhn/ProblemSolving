#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'

map<string, bool> check;
int n, ans;

void initInput() {
    cin >> n;
    check["ChongChong"] = true;
    for (int i = 0; i < n; i++) {
        string name1, name2;
        cin >> name1 >> name2;

        if (check[name1] == true || check[name2] == true) {
            check[name1] = check[name2] = true;
        }
    }
}

void solve() {
    for (auto iter = check.begin(); iter != check.end(); iter++) {
        if (iter->second == true) ans++;
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
