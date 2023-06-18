#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int row, col;
int graph[501][501];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int dp[501][501];

bool isInDomain(int y, int x) {
    return (y >= 0) && (x >= 0) && (y < row) && (x < col);
}

bool canMove(int y, int x, int prev) {
    return isInDomain(y, x) && (graph[y][x] < prev);
}

int DFS(int y, int x) {
    if ((y == row - 1) && (x == col - 1)) return 1;
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (canMove(ny, nx, graph[y][x]))
            dp[y][x] += DFS(ny, nx);
    }
    return dp[y][x];
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> row >> col;
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> graph[y][x];
            dp[y][x] = -1;
        }
    }

    cout << DFS(0, 0) << '\n';

    return 0;
}
