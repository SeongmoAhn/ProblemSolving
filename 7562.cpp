#include <iostream>
#include <queue>
using namespace std;
#define MAX 301

int testCase, tableSize;
pair<int, int> start, dest;
queue<pair<int, int>> q;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void reset() {
    while (!q.empty()) q.pop();
    for (int i = 0; i < tableSize; i++) {
        for (int j = 0; j < tableSize; j++) {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

bool isInDomain(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < tableSize) && (y < tableSize);
}

void BFS(int x, int y) {
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == dest.first && cur.second == dest.second) {
            cout << graph[cur.first][cur.second] << '\n';
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if (!visited[nextX][nextY] && isInDomain(nextX, nextY)) {
                q.push({nextX, nextY});
                visited[nextX][nextY] = 1;
                graph[nextX][nextY] = graph[cur.first][cur.second] + 1;
            }
        }
    }
    
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        cin >> tableSize;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;
        reset();
        BFS(start.first, start.second);
    }

    return 0;
}
