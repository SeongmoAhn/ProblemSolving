#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAP_SIZE 101
#define BOX_SIZE 10
int testCase;
bool graph[MAP_SIZE + 1][MAP_SIZE + 1];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int cnt;

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < MAP_SIZE) && (y < MAP_SIZE);
}

void BFS(int x, int y) {
    q.push({x, y});
    cnt++;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        graph[curX][curY] = 0;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (graph[nextX][nextY] == 1 && isInDomain(nextX, nextY)) {
                q.push({nextX, nextY});
                cnt++;
                graph[nextX][nextY] = 0;
            }
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        int xStart, yStart;
        cin >> xStart >> yStart;
        for (int i = 0; i < BOX_SIZE; i++) {
            for (int j = 0; j < BOX_SIZE; j++) {
                graph[yStart + i][xStart + j] = 1;
            }
        }
    }

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (graph[i][j] == 1)
                BFS(i, j);
        }
    }
    
    cout << cnt << '\n';

    return 0;
}
