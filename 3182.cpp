#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define endl '\n'
#define SIZE 1001

int N, maxCnt, ans;
vector<int> v(SIZE);
bool visited[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];
}

void solve() {
    for (int i = 1; i <= v.size(); i++) {
        memset(visited, 0, SIZE);
        int cur = i, cnt = 0;
        while (!visited[cur]) {
            visited[cur] = 1;
            cnt++;
            cur = v[cur];
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans = i;
        }
    }
    cout << ans;
}

int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
