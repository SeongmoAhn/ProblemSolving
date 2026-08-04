#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int n, m;
vector<string> v, result;

void initInput() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (binary_search(v.begin(), v.end(), input))
            result.push_back(input);
    }
    sort(result.begin(), result.end());
}

void solve() {
    cout << result.size() << endl;
    for (auto it : result) cout << it << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
