#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 100001
#define INF 1e9

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

int n, cnt;
int lastDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prevDay[13];
vector<pair<int, int>> days;

void initInput() {
    cin >> n;
    for (int i = 1; i < 13; i++) prevDay[i] = prevDay[i - 1] + lastDay[i - 1];
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        days.push_back({prevDay[a] + b, prevDay[c] + d});
    }
    sort(days.begin(),days.end());
}

void solve() {
    int start = prevDay[3] + 1, end = prevDay[11] + 30;
    int maxRight = -1, chk = 0;
    for (int i = 0; i < n; i++) {
        int left = days[i].first, right = days[i].second;
        if (left <= start) {
            maxRight = max(right, maxRight);
            if (maxRight > end) {
                chk = 1;
                cnt++;
                break;
            }
        }
        else {
            if (maxRight == -1) break;

            cnt++;
            start = maxRight;
            maxRight = -1;
            i--;
        }
    }
    if (!chk) cout << 0 << endl;
    else cout << cnt << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
