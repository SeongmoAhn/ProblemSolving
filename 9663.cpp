#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define SIZE 16

int N, cnt;
int map[SIZE][SIZE];

void initInput() {
    cin >> N;
}

void dfs(int row) {
    if (row == N) {
        cnt++;
        return;
    }

    vector<pii> del;

    for (int i = 0; i < N; i++) {
        if (map[row][i] == 0) {
            for (int diff = 1; diff < N - row; diff++) {
                if (!map[row + diff][i]) {
                    map[row + diff][i] = 1;
                    del.push_back({row + diff, i});
                }
                if (!map[row + diff][i - diff] && i - diff >= 0) {
                    map[row + diff][i - diff] = 1;
                    del.push_back({row + diff, i - diff});
                }
                if (!map[row + diff][i + diff] && i + diff < N) {
                    map[row + diff][i + diff] = 1;
                    del.push_back({row + diff, i + diff});
                }
            }

            dfs(row + 1);

            while (!del.empty()) {
                auto cur = del.back();
                del.pop_back();
                map[cur.first][cur.second] = 0;
            }
        }
    }
}

void solve() {
    dfs(0);
    cout << cnt << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
