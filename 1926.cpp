#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int row, col, cnt;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool graph[501][501];
vector<int> v;

bool isInDomain(int y, int x) {
    return (x >= 0) && (y >= 0) && (y < row) && (x < col);
}

void DFS(int y, int x) {
    if (!graph[y][x]) return ;

    graph[y][x] = false;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (isInDomain(ny, nx))
            DFS(ny, nx);
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> row >> col;
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> graph[y][x];
        }
    }

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            if (graph[y][x]) {
                cnt = 0;
                DFS(y, x);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());

    if (!v.size()) cout << 0 << '\n' << 0 << '\n';
    else cout << v.size() << '\n' << v[v.size() - 1] << '\n';

    return 0;
}
