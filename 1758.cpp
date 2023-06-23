#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE

int n;
ll sum;
vector<int> v;

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), greater<>());
}

void solve() {
    for (int i = 0; i < n; i++) {
        ll temp = (v[i] - (i));
        if (temp > 0) sum += temp;
    }
    cout << sum << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
