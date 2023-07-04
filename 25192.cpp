#include <iostream>
#include <string>
#include <set>
using namespace std;
#define endl '\n'

set<string> check;
string input;
int n, ans;

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        
        if (input == "ENTER") {
            ans += check.size();
            check.clear();
        }
        else {
            check.insert(input);
        }
    }
    ans += check.size();
}

void solve() {
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
