#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define endl '\n'

int n, m;
vector<string> result;
map<string, int> ma;

void initInput() {
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        string input;
        cin >> input;
        ma[input]++;
        if (ma[input] > 1)
            result.push_back(input);
    }
}

void solve() {
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (string iter : result) {
        cout << iter << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
