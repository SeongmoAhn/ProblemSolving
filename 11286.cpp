#include <iostream>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE
#define PLUS 0
#define MINUS 1

int n;
priority_queue<pair<int, bool>> pq;

void initInput() {
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input > 0) {
            pq.push({-input, PLUS});
        }
        else if (input < 0) {
            pq.push({input, MINUS});
        }
        else {
            if (pq.empty()) cout << 0 << endl;
            else {
                auto cur = pq.top();
                pq.pop();
                if (cur.second == PLUS) cout << -cur.first << endl;
                else cout << cur.first << endl;
            }
        }
    }
}

void solve() {
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
