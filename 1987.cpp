#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m;
string graph[21];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int result = -1;
bool alp[26];

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

bool canMove(int x, int y) {
    return graph[x][y] != '0' && !alp[graph[x][y] - 'A'];
}

void DFS(int x, int y, int len) {
    result = max(result, len);
    alp[graph[x][y] - 'A'] = 1;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isInDomain(nextX, nextY) && canMove(nextX, nextY)) {
            DFS(nextX, nextY, len + 1);
        }
    }
    alp[graph[x][y] - 'A'] = 0;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    DFS(0, 0, 0);

    cout << result + 1 << '\n';

    return 0;
}
