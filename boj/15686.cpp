#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define INT_INF 2e9
#define SIZE 51

int N, M, ans = INT_INF;
int map[SIZE][SIZE], visited[13];
vector<pii> house, chicken, v;

void initInput() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) house.push_back({i, j});
            else if (map[i][j] == 2) chicken.push_back({i, j});
        }
    }
}

int calDist() {
    int sum = 0;
    for (int i = 0; i < house.size(); i++) {
        int hy = house[i].first;
        int hx = house[i].second;
        int dist = INT_INF;

        for (int j = 0; j < M; j++) {
            int cy = v[j].first;
            int cx = v[j].second;
            dist = min(dist, abs(hy - cy) + abs(hx - cx));
        }
        sum += dist;
    }
    return sum;
}

void selectChicken(int idx, int cnt) {
    if (cnt == M) {
        ans = min(ans, calDist());
        return ;
    }

    for (int i = idx; i < chicken.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(chicken[i]);
            selectChicken(i + 1, cnt + 1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

void solve() {
    selectChicken(0, 0);
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
