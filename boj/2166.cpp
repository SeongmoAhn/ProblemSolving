#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE

int n;
vector<pii> v;

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
}

long double solve(int i) {
    long double x1 = v[0].first, y1 = v[0].second;
    long double x2 = v[i].first, y2 = v[i].second;
    long double x3 = v[i + 1].first, y3 = v[i + 1].second;

    return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main(void)
{
    PS_INPUT; 
    initInput();

    long double answer = 0;
    for (int i = 0; i < n - 1; i++) {
        answer += solve(i);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(answer) << endl;

    return 0;
}
