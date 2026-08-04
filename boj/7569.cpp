#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define PII pair<int, int>
#define ll long long
#define SIZE 101

typedef struct {int z; int y; int x;} point;
int X, Y, Z, maxCount = 0;
int dx[] = {-1, 1, 0, 0, 0, 0}, dy[] = {0, 0, -1, 1, 0, 0}, dz[] = {0, 0, 0, 0, -1, 1};
int graph[SIZE][SIZE][SIZE];
queue<pair<point, int>> q;

void initInput() {
    cin >> X >> Y >> Z;
    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < X; k++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) q.push({{i, j, k}, 0});
            }
        }
    }
}

bool isInDomain(int z, int y, int x) {
    return (z >= 0) && (y >= 0) && (x >= 0) && (z < Z) && (y < Y) && (x < X);
}

int BFS() {
    while (!q.empty()) {
        auto curPoint = q.front().first;
        auto curCount = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nextZ = curPoint.z + dz[i];
            int nextY = curPoint.y + dy[i];
            int nextX = curPoint.x + dx[i];
            int nextCount = curCount + 1;

            if (isInDomain(nextZ, nextY, nextX) && !graph[nextZ][nextY][nextX]) {
                graph[nextZ][nextY][nextX] = 1;
                q.push({{nextZ, nextY, nextX}, nextCount});
                maxCount = max(maxCount, nextCount);
            }
        }
    }

    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < X; k++) {
                if (graph[i][j][k] == 0) return 0;
            }
        }
    }
    return 1;
}

void solve() {
    if (BFS()) cout << maxCount << endl;
    else cout << -1 << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
