#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define INF 1e9
#define SIZE

int M, D;
int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string ans[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

void initInput() {
    cin >> M >> D;
}

void solve() {
    int day = D;
    for (int i = 1; i < M; i++) {
        day += date[i];
    }
    cout << ans[day % 7] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
