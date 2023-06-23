#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long

int n, bound;
vector<int> v;
vector<bool> visited(10);
vector<int> result;

void initInput() {
    cin >> n >> bound;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
}

void solve() {
    if (result.size() == bound) {
        for (int i = 0; i < bound; i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            result.push_back(v[i]);
            solve();
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
